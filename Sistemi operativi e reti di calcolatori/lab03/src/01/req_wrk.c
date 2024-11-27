#include "common.h"

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>


// data array
int * data;
/** COMPLETE THE FOLLOWING CODE BLOCK
*
* Add any needed resource 
**/

sem_t *sem_r;
sem_t *sem_w;

int mem_fd;

int request() {
  /** COMPLETE THE FOLLOWING CODE BLOCK
  *
  * map the shared memory in the data array
  **/

 data = (int *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, 0);
  if (data == MAP_FAILED) handle_error("mmap NULL");

  printf("request: mapped address: %p\n", data);

  int i;
  for (i = 0; i < NUM; ++i) {
    data[i] = i;
  }

  printf("request: data generated\n");

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Signal the worker that it can start the elaboration
    * and wait it has terminated
    **/

  if (sem_post(sem_w) == -1) handle_error("sem_post w");
  if (sem_wait(sem_r) == -1) handle_error("sem_wait r");

  printf("request: acquire updated data\n");

  printf("request: updated data:\n");
  for (i = 0; i < NUM; ++i) {
    printf("%d\n", data[i]);
  }

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Release resources
    **/

  if (munmap(data, SIZE) == -1) handle_error("munmap error");
  if (close(mem_fd) == -1) handle_error("close error");

  return EXIT_SUCCESS;
}

int work() {

  /** COMPLETE THE FOLLOWING CODE BLOCK
  *
  * map the shared memory in the data array
  **/

 data = (int *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, 0);

 if (data == MAP_FAILED) handle_error("mmap worker failed");

  printf("worker: mapped address: %p\n", data);

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Wait that the request() process generated data
    **/
  
  sem_wait(sem_w);

  printf("worker: waiting initial data\n");

  printf("worker: initial data acquired\n");

  printf("worker: update data\n");
  int i;
  for (i = 0; i < NUM; ++i) {
    data[i] = data[i] * data[i];
  }

  printf("worker: release updated data\n");

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Signal the requester that elaboration terminated
    **/

   sem_post(sem_r);


  /** COMPLETE THE FOLLOWING CODE BLOCK
   *
   * Release resources
   **/

  if (munmap(data, SIZE) == -1) handle_error("munmap error");
  if (close(mem_fd) == -1) handle_error("close error");

  return EXIT_SUCCESS;
}



int main(int argc, char **argv){

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Create and open the needed resources 
    **/

   sem_unlink(SEM_NAME_REQ);
   sem_r = sem_open(SEM_NAME_REQ, O_CREAT | O_EXCL, 0666, 1);
   if (sem_r == SEM_FAILED) handle_error("sem_open error");

   sem_unlink(SEM_NAME_WRK);
   sem_w = sem_open(SEM_NAME_WRK, O_CREAT | O_EXCL, 0666, 1);
   if (sem_w == SEM_FAILED) handle_error("sem_open error");

   shm_unlink(SHM_NAME);
   mem_fd = shm_open(SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0666);
   if (mem_fd == -1) handle_error("shm_open");

   if (ftruncate(mem_fd, SIZE) == -1) handle_error("ftruncate error");

    int ret;
    pid_t pid = fork();
    if (pid == -1) {
        handle_error("main: fork");
    } else if (pid == 0) {
        work();
        _exit(EXIT_SUCCESS);
    }

    request();
    int status;
     ret = wait(&status);
    if (ret == -1)
      handle_error("main: wait");
    if (WEXITSTATUS(status)) handle_error_en(WEXITSTATUS(status), "request() crashed");


   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Close and release resources
    **/

   if (shm_unlink(SHM_NAME) == -1) handle_error("smh unlink");

   if (sem_unlink(SEM_NAME_REQ) == -1) handle_error("sem unlink");
   if (sem_unlink(SEM_NAME_WRK) == -1) handle_error("sem unlink");

    _exit(EXIT_SUCCESS);

}
