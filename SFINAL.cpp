#include<iostream>
#include<string>
#include<fstream>
#include <limits>
using namespace std;

//THESE ARE THE VARIABLES THAT ARE GIVEN TO THE PROGRAM
	#define Time_to_Counter 0.5
	#define Time_ScanItems 0.5
	#define Time_Pack 0.5
	#define pack_box 10
	#define pack_bag 5
	#define pay_byCard 15
	#define exact 15
	#define notExact 20
	#define receipt_print 0.3
	#define text_data 0.3
	#define idleTime 3

int main()
{
    ifstream fin;
    	// fin.open("project.txt");
    	fin.open("SFINAL.txt");
    	if(!fin.is_open()){
    		cout<<"Cannot Open The File"<<endl;
    		exit(1);
		}
	
	
	//THESE ARE THE USER INPUT
    int no_of_customer;
    int cart_items[10];
    string choices[10]; 
    string payment_method[10];
    string cash_value[10];
    int no_pack[10];
    
   
     

    
    double Total_Dec_Time=0.00;
    double Total_Scanning_Time=0.00;
    double Total_Packing_Time=0.00;
    double Total_Paying_Time=0.00;
    double Total_Printing_Time=0.00;
    double Total_idleTime=0.00;
    double Total_Queue_time=0.00;
    double Ftotal_Queue_time=0.00;


    

    fin>>no_of_customer;
    for(int i=1;i<=no_of_customer;i++)
    {       fin>>cart_items[i]>>choices[i]>>no_pack[i]>>payment_method[i];
        {
            if(payment_method[i]=="Cash" || payment_method[i]=="cash")
            {
                fin>>cash_value[i];
            }
        }
        
        
       
        fin.ignore(numeric_limits<streamsize>::max(),'\n');  
    }
    
cout<<endl;
 cout<<"No. of Customers:"<<no_of_customer<<endl;       
    for(int i=1;i<=no_of_customer;i++)
    {
          
          // DISPLAY OF THE RECEIPT
  cout<<"======================================="<<endl;
            cout<<"Customer No."<<i<<":"<<endl;                
            cout<<"Number of Cart Items: "<<cart_items[i]<<endl;
            if(choices[i]=="Box" || choices[i] =="box")
            {
                cout<<"Preferred Packaging: Box"<<endl;
                cout<<"Number of Boxes:"<<no_pack[i]<<endl;
            }
            if(choices[i]=="Bag" || choices[i]=="bag")
            {
                cout<<"Preferred Packaging: Bag"<<endl;
                cout<<"Number of Bags:"<<no_pack[i]<<endl;
            }
            if(payment_method[i]=="Cash" || payment_method[i]=="cash")
            {
                if(cash_value[i]=="e")
                {
                    cout<<"Preferred Method: Cash(exact)"<<endl;    
                }
                if(cash_value[i]=="ne")
                {
                    cout<<"Preferred Method: Cash(not exact)"<<endl;
                }
            }
            if(payment_method[i]=="Digital" || payment_method[i]=="Digital" )
            {
               cout<<"Preferred Payment Method: Digital"<<endl;
            }
            
            
            
            //THIS IS THE FORMULA OF PROGRAM

            Total_Dec_Time = cart_items[i] * Time_to_Counter;
           Total_Scanning_Time = cart_items[i] * Time_ScanItems;

            if(choices[i]=="Bag" ||  choices[i]=="bag")
            {
                Total_Packing_Time = (cart_items[i] * Time_Pack) + (no_pack[i] * pack_bag);
            }

            if(choices[i]=="Box" || choices[i]=="box")
            {
                Total_Packing_Time = (cart_items[i] * Time_Pack) + (no_pack[i] * pack_box); 
            }
            if(payment_method[i]=="Cash" || payment_method[i]=="cash")
            {
                if(cash_value[i]=="e")
                {
                    Total_Paying_Time = exact;
                }
                if(cash_value[i]=="ne")
                {
                    Total_Paying_Time = notExact;
                }
            }
            if(payment_method[i]=="Digital" || payment_method[i]=="digital")
            {
                Total_Paying_Time = pay_byCard;
            }

            Total_Printing_Time = (cart_items[i] * receipt_print) + text_data;

            if(i<2)
            {
                Total_idleTime = idleTime - 3;  
            }
            else
            {
                Total_idleTime = idleTime;
            }

            Total_Queue_time = Total_Dec_Time + Total_Scanning_Time + Total_Packing_Time + Total_Paying_Time + Total_Printing_Time + Total_idleTime;

            cout<<"_______________________________"<<endl;
            cout<<"Total De-carting Time:       "<<Total_Dec_Time<<endl;
            cout<<"Total Scanning Time:         "<<Total_Scanning_Time<<endl;
            cout<<"Total Packing Time:          "<<Total_Packing_Time<<endl;
            cout<<"Total Paying Time:           "<<Total_Paying_Time<<endl;
            cout<<"Total Receipt Printing Time: "<<Total_Printing_Time<<endl;
            cout<<"Idle Time:                   "<<Total_idleTime<<endl;
            cout<<"Total Customer Queue Time:   "<<Total_Queue_time<<endl;
            cout<<"======================================="<<endl<<endl;
         Ftotal_Queue_time+=Total_Queue_time;
         
    }
    
    cout<<"---------------------------------------"<<endl;
    cout<<"Total Lane Queue Time: "<<Ftotal_Queue_time<<endl;
 cout<<"----------------------------------------"<<endl;
 fin.close();
 
 return 0;
}
