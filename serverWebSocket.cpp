// 29/05/20    from youtube //creating a tcp server in c++

#include<iostream>
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lin")

using namespace std;
int main()
{
    //initilize winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2,2);
    int wsOK = WSAStartup(ver,&wsData);
    if(wsOK)
    {
        cerr<<"can't initilize winsock ! quitting"<<endl;
        return 0;
    }

    //create a sockets
    SOCKET listening = socket(AF_INET,SOCK_STREAM,0);
    if(listening==INVALID_SOCKET)
    {
        cerr<<"can't create a sockets "<<endl;
        return 0;
    }

    //bind the sockets to an ip address and port number
    sockaddr_in hint;
    hint.sin_addr.S_un.S_addr=INADDR_ANY;
    hint.sin_family=AF_INET;
    hint.sin_port=htons(54000);
    bind(listening,(sockaddr*)&hint,sizeof(hint));

    // tell winsock the socket is for listeninig
    listen(listening,SOMAXCONN);

    // wait for a connection
    sockaddr_in client;
    int clientSize =sizeof(client);
    SOCKET clientSocket = accept(listening,(sockaddr*)&client,&clientSize);
    char host[NI_MAXHOST];      //client remote name
    char service[NI_MAXHOST];   //service the client is connect on
    ZeroMemory(host,NI_MAXHOST);    //same as memset(host ,0,NI_MAXHOST)
    /*
    if(getnameinfo((sockaddr*)&client,sizeof(client),host,NI_MAXHOST,service,NI_MAXSERV,0)==0)
    {
        cout<<"connected on port "<<service<<endl;
    }
    else
    {
        inet_ntop(AF_INET,&client.sin_addr,host,NI_MAXHOST);
        cout<<host<<"  connected on port "<<ntohs(client.sin_port)<<endl;
    } */

    //close listening sockets
    closesocket(listening);

    //while loop : accepts and echo message
    char buf[4096];
    while(true)
    {
        ZeroMemory(buf,4096);

        //wait for client to send data
        int byteReceived = recv(clientSocket,buf,4096,0);
        if(byteReceived==SOCKET_ERROR)
        {
            cerr<<" ERROR IN RECEIVED ......Quiting "<<endl;
            break;
        }
        if(byteReceived==0)
        {
            cout<<"client disconnected "<<endl;
            break;
        }

        //message back to client
        send(clientSocket,buf,byteReceived+1,0);

    }

    //close the sockets
    closesocket(clientSize);

    //cleanup winsock
    WSACleanup();
}
