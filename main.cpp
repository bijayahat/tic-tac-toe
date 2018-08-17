//programmed by Bijaya Hatuwal

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <windows.h>


using namespace std;
int score1g = 0;
int score2g = 0;

//-----------loading main game---------------------

class createcomponent{
		
     int checkCrossarray[8][3]={
								 {10,20,30},
								 {40,50,60},
								 {70,80,90},
								 {10,40,70},
								 {20,50,80},
								 {30,60,90},
								 {10,50,90},
								 {30,50,70}
							   };
     int checkboxNum[9]={1,1,1,1,1,1,1,1,1};
	 int score1=0;
	 int score2=0;	
	 int player1[5]={0,0,0,0,0};
	 int p1=0;
	 int player2[5]={0,0,0,0,0};
	 int p2=0;
	 int flag1=0;
	 int flag2=0;
	 DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	 DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	public:
		//-----------initializewindow using constructor--------------
	 createcomponent(){
	 initwindow(screenWidth,screenHeight,"Game Window",-3,-3); 
	 player2[4]=0;
	 floodfill(1,1,8);
	}
	 //-----------closing components using destructor-----------------
	 ~createcomponent(){
	 	closegraph();
	 	//delete this;
	 }
	//----------drawing and vertical horizontal line------------------------
	void initalizecomponet(){
		setcolor(0); //line color set to black
		//---------drawing vertical lines------------------
		line(200,150,200,550);
		line(300,150,300,550);
		line(400,150,400,550);
		line(500,150,500,550);
		//----------drawing horizontal line-------------------
		line(150,200,550,200);
	    line(150,300,550,300);
	    line(150,400,550,400);
	    line(150,500,550,500);
	    
	    setbkcolor(15);
	    setcolor(10);
	    settextstyle(4,0,4);
	    outtextxy(200,50,"TICK TACK TOE BY --Bijaya Hatuwal");
	    
	    setcolor(0);
	    settextstyle(4,0,3);
	    outtextxy(750,350,"Player-1");
		outtextxy(950,350,"Player-2");
		setcolor(3);
		outtextxy(750,380,"Score: ");
		outtextxy(950,380,"Score: ");
		setcolor(1);
		outtextxy(750,550,"Replay");
		setcolor(4);
		outtextxy(950,550,"Exit");
	}
	//-------------showing players face---------
	void showFace(){
		//-----player1face------
		setcolor(5);
		circle(800,200,70);
		circle(750,150,20);
		circle(850,150,20);
		if(score1==0)
		  line(850,220,750,220);
		else  
		  arc(800,220,180,0,50);
		
		//-----player2face-----
		setcolor(4);
		circle(1000,200,70);
		circle(950,150,20);
		circle(1050,150,20);
		if(score2==0)
		  line(950,220,1050,220);
		else  
		  arc(1000,220,180,0,50);
		
	}
	//-------gettingmouse component and sending box position----------------------------
	int mousework(){
	 int x=0,y=0;
	  while(1)
	  {
	    if(ismouseclick(513))
		{	
			x = mousex();
			y = mousey();
			break;
		}
		delay(10);
       }
	
	 cout<<x<<" and "<< y <<" "<<ismouseclick(513)<< endl;
	 
		 if(x>=200&&x<=300&&y>=200&&y<=300)
		    { return 10;}
		 if(x>=300&&x<=400&&y>=200&&y<=300)
		    { return 20; }   
		 if(x>=400&&x<=500&&y>=200&&y<=300)
		    { return 30;}
		 if(x>=200&&x<=300&&y>=300&&y<=400)
	        { return 40;}
		 if(x>=300&&x<=400&&y>=300&&y<=400)
	        { return 50;}
		 if(x>=400&&x<=500&&y>=300&&y<=400)
	        { return 60;}
		 if(x>=200&&x<=300&&y>=400&&y<=500)
	         {return 70;}
		 if(x>=300&&x<=400&&y>=400&&y<=500)
	        { return 80;}
		 if(x>=400&&x<=500&&y>=400&&y<=500)
	         {return 90; }  
	     if(x>=753&&x<=860&&y>=548&&y<=573)
	         {return 101; } 
		 if(x>=952&&x<=1009&&y>=550&&y<=575)
	         {return 102; } 	    
	     
		   return 901;  

		  
	}
	
    //------------drawing characters in box----------------------
	int showBoxChar(int boxNum,int player){
		
		//-----------drawing cross----------
		setcolor(0);
		if(player%2==1)
		{
		
			if(boxNum==10&&checkboxNum[0]==1)
			     { 
			       flag1=1;
			       checkboxNum[0]=0;
			       line(220,220,280,280);
			       line(220,280,280,220);
				 }
			   else if(boxNum==20&&checkboxNum[1]==1)
			    { 
			     flag1=1;
			     checkboxNum[1]=0;
			     line(320,220,380,280);
			       line(320,280,380,220);
				 }
			   else if(boxNum==30&&checkboxNum[2]==1)
			     { 
			     flag1=1;
			     checkboxNum[2]=0;
			     line(420,220,480,280);
			       line(420,280,480,220);
				 }
			   else if(boxNum==40&&checkboxNum[3]==1)
			     { 
			     flag1=1;
			     checkboxNum[3]=0;
			     line(220,320,280,380);
			       line(220,380,280,320);
				 }
			   else if(boxNum==50&&checkboxNum[4]==1)
			     { 
			     flag1=1;
			     checkboxNum[4]=0;
			     line(320,320,380,380);
			       line(320,380,380,320);
				 }
			   else if(boxNum==60&&checkboxNum[5]==1)
			     { 
			     flag1=1;
			     checkboxNum[5]=0;
			     line(420,320,480,380);
			       line(420,380,480,320);
				 }
			   else if(boxNum==70&&checkboxNum[6]==1)
			     { 
			     flag1=1;
			     checkboxNum[6]=0;
			     line(220,420,280,480);
			       line(220,480,280,420);
				 }
			   else if(boxNum==80&&checkboxNum[7]==1)
			     { 
			     flag1=1;
			     checkboxNum[7]=0;
			     line(320,420,380,480);
			       line(320,480,380,420);
				 }
			   else if(boxNum==90&&checkboxNum[8]==1)
			      { 
			      flag1=1;
			      checkboxNum[8]=0;
			      line(420,420,480,480);
			       line(420,480,480,420);
				 }
				 else{return 0;}
				 
			 
		}
		//-----------------drawing circle------------------
		if(player%2==0){
			
			   if(boxNum==10&&checkboxNum[0]==1)
			   { 
			      flag2=1;
			      checkboxNum[0]=0;
			      circle(250,250,40);
			   }
			   else if(boxNum==20&&checkboxNum[1]==1)
			   { 
			     flag2=1;
			     checkboxNum[1]=0;
			     circle(350,250,40);
			   }
			   else if(boxNum==30&&checkboxNum[2]==1)
			   { 
			    flag2=1;
			     checkboxNum[2]=0;
			     circle(450,250,40);
			   }
			   else if(boxNum==40&&checkboxNum[3]==1)
			   { 
			     flag2=1;
			     checkboxNum[3]=0;
			     circle(250,350,40);
			   }
			   else if(boxNum==50&&checkboxNum[4]==1)
			   { 
			     flag2=1;
			     checkboxNum[4]=0;
			     circle(350,350,40);
			   }
			   else if(boxNum==60&&checkboxNum[5]==1)
			    { 
			    flag2=1;
			    checkboxNum[5]=0;
			    circle(450,350,40);
				}
			   else if(boxNum==70&&checkboxNum[6]==1)
		        { 
		        flag2=1;
		        checkboxNum[6]=0;
			    circle(250,450,40);
			    }
			   else if(boxNum==80&&checkboxNum[7]==1)
			   { 
			    flag2=1;
			     checkboxNum[7]=0;
			     circle(350,450,40);
			   }
			   else if(boxNum==90&&checkboxNum[8]==1)
			   { 
			     flag2=1;
			     checkboxNum[8]=0;
			      circle(450,450,40);
			   }
			   else{return 0;}
			      
			  }
			  
			   
	   
	}
	
	 //-------incrementing the pl and p2 if characters are drawn on screen---------------
	void increasePlayerCharacterCount(){
		
			  if(flag1==1)
			     p1=p1+1;
			  if(flag2==1)
			     p2=p2+1; 
			 //-------------if flag is set to 1 resetting to 0 agin
			 flag1=0;
			 flag2=0;    
	}
	
	//--------------detecting the plyaers choices----------
	void fillplayersPattern(int player,int boxNum){
		
		//------------setting filled character box of respective box--------------------
		if(player%2==1)
		  {
		  	cout<<"the player is: 1"<<" and boxNO is "<<boxNum<<endl; 
		   player1[p1]=boxNum;
	      }
	     if(player%2==0)
		  {
		  	cout<<"the player is: 2"<<" and boxNO is "<<boxNum<<endl;
		   player2[p2]=boxNum;  
	      }
		//--------------checking for any score-----------------
	   
    }
    //
    int checkCharacterPattern()
	{
    	int i,j,k;
    	int status = 0;
    	
    	//------------for 1st player--------------------
    
	    	for(i=0;i<=7;i++)
				{
					status = 0;
					for(j=0;j<=2;j++)
					{
						
						for(k=0;k<5;k++)
						{
							if(player1[k]==checkCrossarray[i][j])
							{
								status=status+1;
				
						    }
						    
						}
						
					}
					
					        if(status==3)
						    {
								score1=1;
								Beep(1000,200);
								cout<<"the status is 3 "<<endl;
								   setcolor(0);
									switch(i)
									{
										case 0:
											line(250,250,450,250);
											break;
									    case 1:
											line(250,350,450,350);
											break;
										case 2:
											line(250,450,450,450);
											break;
										case 3:
											line(250,250,250,450);
											break;
										case 4:
											line(350,250,350,450);
											break;
										case 5:
											line(450,250,450,450);
											break;
										case 6:
											line(250,250,450,450);
											break;
									    case 7:
										    line(450,250,250,450);
											break;
										default:
										    cout<<"There is error in finalizing the game and i is:"<<i<<endl;											
											    
									}
								return status;	
								
				             }
					
				}
    
        //------------for second player-----------------
    	
	    	for(i=0;i<=7;i++)
				{
					status = 0;
					for(j=0;j<=2;j++)
					{
						
						for(k=0;k<5;k++)
						{
							if(player2[k]==checkCrossarray[i][j])
							{
									status=status+1;
								
						    }
									
						}
						
						            
				    }		
					
									if(status==3)
							        {
							        	score2=1;
							        	Beep(1000,200);
								  	   cout<<"The status is 3 "<<endl;
								  	   setcolor(0);
										switch(i)
										{
											case 0:
												line(250,250,450,250);
												break;
										    case 1:
												line(250,350,450,350);
												break;
											case 2:
												line(250,450,450,450);
												break;
											case 3:
												line(250,250,250,450);
												break;
											case 4:
												line(350,250,350,450);
												break;
											case 5:
												line(450,250,450,450);
												break;
											case 6:
												line(250,250,450,450);
												break;
										    case 7:
											    line(450,250,250,450);
												break;
											default:
											    cout<<"There is error in finalizing the game and i is: "<<i<<endl;											
											    
								        }
								      return status;  
								    }
				                	
						       
	
				}
				
			return status;	
				
    }
	//------------------check if all the boxes are filled------------------
	int checkifboxesFilled(){
		int flag=0;
		int i;
		for(i=0;i<=8;i++)
		{
			
			if(checkboxNum[i]==1)
			  {
			  	return flag;
			  }
		}
		flag = 1;
		cout<<"Boxes are filled"<<endl;
		//----------checking if player1 and plyaer2 are filled or not-------------------
		cout<<"the player1 boxes are: ";
		for(i=0;i<=4;i++)
		{
			cout<<player1[i]<<" ";
		}
		cout<<endl<<"the player2 boxes are: ";
		for(i=0;i<=4;i++)
		{
			cout<<player2[i]<<" ";
		}
		
		return flag;
		
		
	}
	
	//-------------showing scores of players--------------------
	void showScores(){
		  stringstream strs;
		  score1g=score1g+score1;
		  strs << score1g;
		  string temp_str = strs.str();
		  char* c = (char*) temp_str.c_str();
		outtextxy(880,380,c);
		
		  stringstream strss;
		  score2g=score2g+score2;
		  strss << score2g;
		  string temp_strs = strss.str();
		  char* ch = (char*) temp_strs.c_str();
		outtextxy(1070,380,ch);
	}
	
	//------------exit game---------------
	void exitgame(){
		closegraph();
	    exit(1);
	}
	
};




//------------main starts------------

int main(int argc, char** argv) {
	
    
	while(1)
	{   
	    int x=0;
	    int y=0;
	    int player=1;
	    int checkCharcacterinbox;
		int boxNum=0;
		createcomponent obj1;
		obj1.initalizecomponet();
		obj1.showFace();
		obj1.showScores();
		while(1){
			boxNum = obj1.mousework();
			if(boxNum==102)
			 {
			 	obj1.exitgame();
			 }
			
			clearmouseclick(513);
			
			if(player%2!=0)
				player=1; //decidig the player as first
			if(player%2==0) 
			   player=2; //deciding the playe as second
			
			checkCharcacterinbox=obj1.showBoxChar(boxNum,player);
			if(checkCharcacterinbox!=0)
			  {
			  	obj1.fillplayersPattern(player,boxNum);
			  	obj1.increasePlayerCharacterCount();
			    player=player+1;
		      }
		      
			   if(obj1.checkCharacterPattern()>=3)
			   {
			     obj1.showScores();
			     obj1.showFace();
			     break;
			   }
			   if(boxNum==101)
				 {
				 	break;
				 }
			   
			delay(1000);
		  
	    }
	    
	    
	    while(1)
	  {
	  	int flag=0;
	    if(ismouseclick(513))
		{	
			x = mousex();
			y = mousey();
		}
		clearmouseclick(513);
		if(x>=753&&x<=860&&y>=548&&y<=573)
	         flag=1;
		if(x>=952&&x<=1009&&y>=550&&y<=575)
	         flag=2;
	    if(boxNum==101)
		     flag=1;
		if(boxNum==102)
			flag=2;     
		if(flag==2)
		   {
		   	 obj1.exitgame();
	       }
	    if(flag==1)
		  break;		      
		delay(10);
       }
       
       
	    
	}
		return 0;
}
