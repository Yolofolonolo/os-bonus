SYSCALL_DEFINE1(writer, char *, msng)
{   mutex_lock(&readnwrite);
    char buffer[8];
    long copied = strncpy_from_user(buffer, msng, sizeof(buffer));
    if (copied < 0 || copied == sizeof(buffer))
        return -EFAULT;
    enqueue(buffer);
    mutex_unlock(&readnwrite);
    return 0;
    
}

SYSCALL_DEFINE1(reader, char *, msng)
{
    mutex_lock(&readnwrite);
    char buffer[8];
    dequeue(buffer);
    strncpy_to_user(msng,buffer,sizeof(buffer));
    mutex_unlock(&readnwrite);
    return 0;

}


static int front = -1, rear = -1;  
static int queue[30];
static void enqueue()
{	char item;         
    if(rear == 30-1)  
    {    
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;   
}  
    
static char dequeue()
{	char item;   
    if (front == -1 || front > rear)  
    {  
        return;        
    }  
    else  
    {	item = queue[front];  
        if(front == rear)  
        {	front = -1;  
            rear = -1 ;  
        }  
        else   
        {	front = front + 1;  
        }   
    }     
}
static char dequeue()
{	char item;   
    if(before != -1 || before < end){
		item = queue[before];  
        if(before != end){
			before = before + 1;
		}
        else{
			before = -1;  
            end = -1;
		} 
	} 
	  
    else{
		return item;
    }   
	 
}





static struct mutex yash; 
static int before = -1, end = -1;  
static char queue[20];
static void enqueue(char item)
{	char item;      
    if(end == 20-1)  
    {    
        return;  
    }  
    if(before != -1 && end != -1){
		end = end+1;
	} 
    else{
		before = 0;  
        end = 0; 
	} 
    queue[end] = item;   
}
    
static char dequeue()
{	char item;   
    if(before != -1 || before < end){
		item = queue[before];  
        if(before != end){
			before = before + 1;
		}
        else{
			before = -1;  
            end = -1;
		} 
	} 
	  
    else{
		return item;
    }   
	 
}