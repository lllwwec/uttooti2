
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca3.h"


//struct foe users
typedef struct user
{
    char username[20];
    char password[20];
    int num_of_post;
    struct user *next;
}user;


//struct for post
typedef struct post{
    char cotext[100];
    int num_of_like;
    int id;
    user *poster;

    struct post *next;
}post;


int main(){
     user *logged_in_user=NULL;
     user *headuser=newuser("najme", "madadi");
     post *headpost=newpost(" sssskk",headuser);
    

   while(1){
    //getting input
 char str[100];
 char str2[100];
 char str3[100];

    printf("please enter your command\n");
    scanf("%[^\n]%*c", str);
    strcpy(str2,str);
    strcpy(str3,str);

  
//sign up
//getting username

   if(strcmp(token_return(str,0),"signup")==0){
    char username[100];
    char password[100];
    strcpy(username,token_return(str2,1));
    strcpy(password,token_return(str3,2));
    signup(headuser,username,password);//becarefull that my sign up doesnt work
    
    }

//login
   if(strcmp(token_return(str,0),"login")==0){

    char username[100];
    char password[100];
    strcpy(username,token_return(str2,1));
    strcpy(password,token_return(str3,2));
    logged_in_user= login(headuser,&logged_in_user,username,password);
    
    fflush(stdin);
    
   }
    


  if(strcmp(token_return(str,0),"logout")==0){
    logout(&logged_in_user);

    fflush(stdin);
  }


  if(strcmp(token_return(str,0),"post")==0){
    //get the context
    char context[100];
     for(int i=5; str2[i]!='\0'; i++){

            context[i-5]=str2[i];
    }

    post1(headpost,&logged_in_user,context);
    //free the context
 for(int i=0; context[i]!='\0'; i++){
        context[i]='\0';
 }
    fflush(stdin); 

  }


  if(strcmp(token_return(str,0),"delet")==0){
    char post_id[100];
    int id;
    strcpy(post_id,token_return(str2,1));
    id=post_id[0]-48;
    

    delet(headpost,&logged_in_user,id);

    fflush(stdin);
  }
  
  if(strcmp(token_return(str,0),"like")==0){
    char username[100];
    char post_id[100];
    int id;
    strcpy(username,token_return(str2,1));
    strcpy(post_id,token_return(str3,2));;
    id=post_id[0]-48;
    like(headpost,username,id);

    fflush(stdin);
  }


  if(strcmp(token_return(str,0),"info")==0){
    info(headpost,headuser,&logged_in_user);

    fflush(stdin);
  }


  if(strcmp(token_return(str,0),"find_user")==0){
    char username[100];
     strcpy(username,token_return(str2,1));
    find_user(headuser,headpost,username);

    fflush(stdin);
  }

else{
    printf("command eror\n");
    printf("please try again\n");
}
  
}


}