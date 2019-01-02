#include "pipe_networking.h"

void process(char *msg){
  int i;
  for(i=0; i<strlen(msg);i++){
    msg[i] +=10;
  }
}

static void sighandler(int signo){
if(signo == SIGINT){
  remove("mario");
  printf("[server] removing wkp\n");
  exit(0);
}
}

int main() {

  signal(SIGINT,sighandler);
  int to_client;
  int from_client;

  while(1){
    server_handshake();
    from_client=open("mario",O_RDONLY);
  if(!fork()){
  from_client = subserver_handshake(&from_client, &to_client );
  char msg[BUFFER_SIZE];
  while(read(from_client,msg,BUFFER_SIZE)){
    printf("[subserver %d] recieved:%s\n", getpid(),msg);
    process(msg);
    write(to_client,msg,BUFFER_SIZE);
  }
  exit(0);
  }
  else{
    close(from_client);
    close(to_client);
    remove("mario");
  }
}}
