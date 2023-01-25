

//return part of the string
char *token_return(char str[40], int n_om){
    
     char *mytoken;
    char *return_string;

   mytoken = strtok(str," ");
   int count=0;

   while( mytoken != NULL ) {
     if(count==n_om){


        return mytoken;
        
     }
     
     else{
        count++;
     }
      
 mytoken = strtok(NULL," ");
   }
   //if our string is short and we did not find the number
   printf("too short command\n");

}

//add a new node and the pointer is to null
user* newuser(char username[20], char password[20]){
    user* ouput_user=(user*)malloc(sizeof(user));
    strcpy(ouput_user->username, username);
    strcpy(ouput_user->password, password);
    ouput_user->num_of_post=0;

    ouput_user->next=NULL;
    return ouput_user;
}


//add the newnode to list
void adduser(user* headuser, user* newuser){
    user* curr_user;
    for(curr_user=headuser; curr_user->next!=NULL; curr_user=curr_user->next);
    curr_user->next=newuser;
}


//is for checking
void print_user(user* headuser){
    int index=0;

    user* curr_user=headuser;
    while(curr_user!=NULL){
        printf("the username of the %d user is : %s\n",index, curr_user->username);
        printf("the password of the %d user is : %s\n",index, curr_user->password);
        printf("^^^^^^^^^^^^^^^^^^^^\n");

        index++;
        curr_user=curr_user->next;
    }
}



post* newpost(char context[100], user* poster){
    post* output=(post*)malloc(sizeof(post));
    strcpy(output->cotext, context);
    output->poster=poster;
    output->id=0;
    output->num_of_like=0;


    output->next=NULL;
    return output;
}



void addpost(post* headpost, post* newpost){
    
    post* curr_post;
    for(curr_post=headpost; curr_post->next!=NULL; curr_post=curr_post->next){
        curr_post->next=newpost;

    }
    
}



void print_post(post* headpost){
    
    post* curr_post=headpost;
    while(curr_post!=NULL){
        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("the text of the %d post is: %s\n",curr_post->id, curr_post->cotext);
        printf("the number of likes of the %d post is: %d\n",curr_post->id, curr_post->num_of_like);
        
        printf("*****************************\n");

        curr_post=curr_post->next;
    }

}



void post1(post *headpost, user **logged_in_user, char context[100]){
    
    
 int index = 0;

    post* curr_post=headpost;
   // for(curr_post=headpost; curr_post->next!=NULL; curr_post=curr_post->next);
  while(curr_post->next!=NULL){
    
   curr_post=curr_post->next;

   }
    //strcpy(curr_post->cotext,context);
   
   post *new_post=newpost(context,*logged_in_user);
   (*logged_in_user)->num_of_post++;
   new_post->id=(*logged_in_user)->num_of_post+1;
   curr_post->next=new_post;
   printf("your post is posted\n");
       
}


void signup(user* headuser,char username[20], char password[20]){
    char str1[20];
    char str[20];
    int value;

    //cheking is there the same username or not
    user *curr_user=headuser;
    while(curr_user!=NULL){
        if(strcmp(curr_user->username,username)==0){
            
            printf("there is an acount with this choose another username\n ");
            return;
        }
        curr_user=curr_user->next;
    }

    adduser(headuser, newuser(username, password));
    printf("you are signed up succesfully\n");

}


user* login(user* headuser,user** logged_in_user,char username[20], char password[20]){
    if((*logged_in_user)!=NULL){
        printf("another user has logged in\n");
        printf("please log out first\n");
        return;
    }
    user *curr_user=headuser;
    while(curr_user!=NULL){
        //logged in 
        if(strcmp(curr_user->username,username)==0 && strcmp(curr_user->password, password )==0){
            printf("you are logged in succesfully\n");
            return curr_user;
           // printf("you are now logged in\n");
            
        }

        if(strcmp(curr_user->username,username)==0 && strcmp(curr_user->password, password )!=0){
            printf("the password is not correct please try again\n");
            return;////////////////////////////
        }
        curr_user=curr_user->next;
    }

    
            printf("there is not such a username\n");
            printf("please try again\n");
            return;
        

}


void delet(post* headpost,user** logged_in_user,int id){
    post* curr_post=headpost;
    post* hold;
    while(curr_post!=NULL){
        if(curr_post->poster==(*logged_in_user)){
            if(curr_post->id==id){
               
               hold=curr_post->next;
               curr_post->next=curr_post->next->next;
               free(hold);
               //changing the num of poster post to not make problem for giving id
               curr_post->poster->num_of_post--;
               printf("your post deleted succesfully\n");
               
            }
           
        if(curr_post->poster==(*logged_in_user)){
            if(curr_post->id>id){
                curr_post->id--;
            }
            
        
        }
            
        }

       
        curr_post=curr_post->next;
    }

}



void like(post* headpost, char target_username[20],int target_id){
    post* curr_post=headpost;
    while(curr_post!=NULL){
        if(strcmp(curr_post->poster->username,target_username)==0){
            if(curr_post->id==target_id+1){
                curr_post->num_of_like++;
                printf("you liked %s's post\n",curr_post->poster->username);
                return;
            }
            
        }
        curr_post=curr_post->next;
    }
    printf("sorry there is not such a username or the user doesnt have this post \n");
}


void info(post* headpost,user* headuser, post**logged_in_user){
    post* curr_post=headpost;
    user* curr_user=headuser;

    while(curr_user!=NULL){
        if(curr_user==(*logged_in_user)){
            printf("the username is: %s \n",curr_user->username);
            printf("the password is: %s \n",curr_user->password);
        }
        curr_user=curr_user->next;
        }

    
    while(curr_post!=NULL){
        if(curr_post->poster==*logged_in_user){
            printf("---------------------------------------------------------------\n");
            printf("post id: %d\n",curr_post->id-1);
            printf("the context:%s\n",curr_post->cotext);
            printf("the number of likes for this post: %d\n",curr_post->num_of_like );
            printf("---------------------------------------------------------------\n");
        }
        curr_post=curr_post->next;
    }
}



void find_user(user* headuser,post* headpost,char username[20]){
    post* curr_post=headpost;
    user* curr_user=headuser;

    while(curr_user!=NULL){
        if(strcmp(curr_user->username,username)==0){
            while(curr_post!=NULL){

                if(strcmp(curr_post->poster->username,username)==0){
    
                    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
                    printf("post id: %d\n",curr_post->id-1);
                    printf("the context:%s\n",curr_post->cotext);
                    printf("the number of likes for this post: %d\n",curr_post->num_of_like );
                    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
                    
                }
                curr_post=curr_post->next;
            }
            return;
        }
    curr_user=curr_user->next;
    }
    printf("there is not such a username\n");
}



void logout(user** logged_in_user){

    if((*logged_in_user)!=NULL){
        *logged_in_user=NULL;
        printf("you are logged out succesfully\n");
    }
    

    else{
        printf("no one has logged in\n");
    }
}
