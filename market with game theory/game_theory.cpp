#include "gridlabd.h"
#include "game_theory.h"
#include "auction.h"
#include "stub_bidder.h"
#include <math.h>
 node *head=NULL;
 void init()
 {
	head= (node *)malloc(sizeof(node));
	head->next=head;
 }
 void create_list(char *name, double q_i, double c_i)
 {
	 node *list= (node *)malloc(sizeof(node));
	 list->q_i=q_i;
	 list->c_i=c_i;
     strcpy(list->name,name);
     list->next=head->next;
	 head->next=list;
	 
 }
 double sum(double c_i)
 {
	 double total_sum=0.0;
     node* list;
     //list=head;
	  for(list=head->next;list!=head;list=list->next)
	  {
	      total_sum=total_sum+list->c_i;
	  }
 
	  total_sum=total_sum-c_i;
      return total_sum;
 }
  double sum2(double c_i)
 {
	 double total_sum=0.0;
     node* list;
     //list=head;
	  for(list=head->next;list!=head;list=list->next)
	  {
	      total_sum=total_sum+list->q_i;
	  }
 
	 
      return total_sum;
 }
void print_results(double d_0,int counter)
{
	   node* list;
	   double new_quantity=0.0;
	   double demand=0.0;

	   char amount[30];
	   for(list=head->next;list!=head;list=list->next)
	   {  
		  if(list->c_i==0.0)
		  {
			// demand=demand+list->q_i;
			 
		  }
	   }

	   demand=200000;
	   printf("total demand:%f \n\n\n",demand);
      //list=head;
      for(list=head->next;list!=head;list=list->next)
	  {   
		  
		  if(list->c_i!=0.0)
		  {
			  //printf("new_quantity:  %f",(demand-counter*0.5*(list->c_i)+0.5*sum(list->c_i))/(counter+1));
				  OBJECT *bidder=gl_get_object(list->name);
		    	  sprintf(amount,"%f",(demand-counter*0.5*(list->c_i)+0.5*sum(list->c_i))/(counter+1));
				 
				  if((demand-counter*0.5*(list->c_i)+0.5*sum(list->c_i))/(counter+1) < 0 )
				  {
					  printf("WERTT");
					  char amount2[20];
					  sprintf(amount2,"%f",list->q_i);
					  gl_set_value_by_name(bidder,"quantity",amount2);	
					  printf("amoount2 :%s %f %f\n",amount2,demand/(counter+1) , counter*0.5*(list->c_i)+0.5*sum(list->c_i)/(counter+1));
				  }
				  else
				  {
					   printf("WERTT111111");
					 gl_set_value_by_name(bidder,"quantity",amount);	
					 printf("amoount :%s %f %f\n",amount,demand/(counter+1) , counter*0.5*(list->c_i)+0.5*sum(list->c_i)/(counter+1));
				  }
		  }
         
	  }
	  	  

}


void find_solution(double d_0)
{
	
	//find into the list of objects only the stub_bidders
	//put each quantity and cost from each stub_bidder into an array 
    //allocate the matrix
	//fill the matrix
	init();
	static FINDLIST *nodes=NULL;
	nodes=gl_find_objects(FL_NEW,FT_CLASS,SAME,"auction",FT_END);
	OBJECT *first= gl_find_next(nodes,NULL);
	OBJECT *i=first;
	OBJECT *ii;
	int counter=0;
	printf("\n\n\n\n\n\n\n\n\nTELOSSSSSSSSSSSSSSSSSSSSSSSSSSS\n\n\n\n\n");
	for(i=first;i!=NULL;i=i->next)
	{  
				if(gl_object_isa(i,"auction"))
				{
					PROPERTY *factory=gl_get_property(i,"second_bidder");
					if(factory!=NULL)
					{
					//	printf("%s ",i->name);
						for(ii=i;ii!=NULL;ii=ii->next)
						{  
						//	printf("%s ",ii->name);
							if(gl_object_isa(ii,"stub_bidder"))
							{
								//printf("%s ",ii->parent->name);
									OBJECT *parent_2=gl_get_object(ii->parent->name);
									int64 *value2=gl_get_int64_by_name(ii,"role");

									
					    			if(strcmp(parent_2->name,i->name)==0 && (*value2)==1)
							    	{	
									    double *cost_check= gl_get_double_by_name(ii,"cost");
										
									      if((*cost_check) !=0)
										  {    printf("game\n\n\n");
											 double *q_i=gl_get_double_by_name(ii,"quantity");
												double *cost=gl_get_double_by_name(ii,"cost");
												int64 *value=gl_get_int64_by_name(ii,"role");
					  				         
												if((*value)!=0)
												{
													counter++;
													printf("game2\n\n\n");
													printf("%s %f %d n\n\n\n",ii->name,*q_i,counter);
													create_list(ii->name,*q_i,(*cost));
												}
												else
												{
													 printf("game3\n\n\n");
												     create_list(ii->name,*q_i,0.0);
												
												}
											
										  }
							   }
							}
						}
						
					}
				}
				   
	}
    
	print_results(d_0,counter);
	

}

