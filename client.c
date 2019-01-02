#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while(1){
    char msg[BUFFER_SIZE];
    printf("INPUT MESSAGE:\n");
    fgets(msg,BUFFER_SIZE,stdin);
    msg[strlen(msg)-1] = 0;
    write(to_server,msg,BUFFER_SIZE);

    char response[BUFFER_SIZE];
    read(from_server,response,BUFFER_SIZE);
    printf("[client] recieved: %s\n",response);
  }
}
