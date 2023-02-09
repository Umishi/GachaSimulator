#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

class mode1{
public:
    void sim();
    void firstpattern();
    void secondpattern();
    void thirdpattern();
    void output();

private:
    string gamename;
    string charaname;
    int trials=10000;
    int average;
    double lowest=0;
    double lower=0;
    double low=0;
    double middle=0;
    double high=0;
    double higher=0;
    double highest=0;
    int firstrange =50;
    int secondrange =100;
    int thirdrange =200;
    int fourthrange =400;
    int fifthrange =600;
    int sixthrange =1000;

};

void mode1::sim(){

    cout<<"In the pick up => 1"<<endl;
    cout<<"Out of the pick up => 2"<<endl;
    cout<<"No pick up => 3"<<endl;
    int pattern;
    cin>>pattern;
    if(pattern==1){
        mode1 action;
        action.firstpattern();
    }
    else if(pattern==2){
        mode1 action;
        action.secondpattern();
    }
    else{
        mode1 action;
        action.thirdpattern();

    }

}


void mode1::firstpattern(){
    double percentage;
    int pickup;
    int competitor;
    cout<<"Game name => "<<endl;
    cin>>gamename;
    cout<<"Charactor name => "<<endl;
    cin>>charaname;
    cout<<"Percentage? =>"<<endl;
    cin>>percentage;
    cout<<"Pick up percentage? =>"<<endl;
    cin>>pickup;
    cout<<"How many competitors? =>"<<endl;
    cin>>competitor;
    int sum=0;

    for(int j=0 ; j<trials ; ++j){
        int num=0;
        while(1){
            int a=rand()%1000;
            if(a<percentage*10){

                int b=rand()%100;
                if(b<pickup){
                    int c=rand()%competitor;
                    if(c==0){
                        num++;
                        break;

                    }
                    else{
                        num++;

                    }

                }
                else{
                    num++;
                }

            }

            else{
                num++;
            }

        }
        sum=sum+num;
     if(num<=firstrange){
    lowest++;
  }
else if(num>firstrange && num<=secondrange){
    lower++;
}
else if(num>secondrange && num<=thirdrange){
    low++;
}
else if(num>thirdrange && num<=fourthrange){
    middle++;
}
else if(num>fourthrange && num<=fifthrange){
    high++;
}
else if(num>fifthrange && num<=sixthrange){
   higher++;
}
else{
   highest++;
}
    }
    average=sum/trials;
    output();
    }


void mode1::secondpattern(){
    double percentage;
    int pickup;
       int competitor;
    cout<<"Game name => "<<endl;
    cin>>gamename;
    cout<<"Charactor name => "<<endl;
    cin>>charaname;
    cout<<"Percentage? =>"<<endl;
    cin>>percentage;
    cout<<"Pick up percentage? =>"<<endl;
    cin>>pickup;
    cout<<"How many competitors? =>"<<endl;
    cin>>competitor;
    int sum=0;
    for(int j=0 ; j<trials ; ++j){
        int num=0;
        while(1){
            int a=rand()%1000;
            if(a<percentage*10){
                int b=rand()%100;
                if(b>=pickup){
                    int c=rand()%competitor;
                    if(c==0){
                        num++;
                        break;

                    }
                    else{
                        num++;

                    }

                }
                else{
                    num++;
                }

            }

            else{
                num++;
            }

        }
        sum=sum+num;
        if(num<=firstrange){
       lowest++;
     }
   else if(num>firstrange && num<=secondrange){
       lower++;
   }
   else if(num>secondrange && num<=thirdrange){
       low++;
   }
   else if(num>thirdrange && num<=fourthrange){
       middle++;
   }
   else if(num>fourthrange && num<=fifthrange){
       high++;
   }
   else if(num>fifthrange && num<=sixthrange){
      higher++;
   }
      else{
         highest++;
      }
    }
    average=sum/trials;
    output();
}

void mode1::thirdpattern(){
    double percentage;
       int competitor;
    cout<<"Game name => "<<endl;
    cin>>gamename;
    cout<<"Charactor name => "<<endl;
    cin>>charaname;
    cout<<"Percentage? =>"<<endl;
    cin>>percentage;
    cout<<"How many competitors? =>"<<endl;
    cin>>competitor;
    int sum=0;
    for(int j=0 ; j<trials ; ++j){
        int num=0;
        while(1){
            int a=rand()%1000;
            if(a<percentage*10){
                int c=rand()%competitor;
                if(c==0){
                    num++;
                    break;
                }
                else{
                    num++;
                }

            }

            else{
                num++;
            }

        }
        sum=sum+num;
        if(num<=firstrange){
       lowest++;
     }
   else if(num>firstrange && num<=secondrange){
       lower++;
   }
   else if(num>secondrange && num<=thirdrange){
       low++;
   }
   else if(num>thirdrange && num<=fourthrange){
       middle++;
   }
   else if(num>fourthrange && num<=fifthrange){
       high++;
   }
   else if(num>fifthrange && num<=sixthrange){
      higher++;
   }
      else{
         highest++;
      }
    }
    average=sum/trials;
    output();
}

void mode1::output(){
    ofstream results("results.txt",ios::app);
    results<<endl<<gamename<<endl;
    results<<charaname<<endl<<endl;
    results<<"Average "<<average<<endl;
    results<<"-"<<firstrange<<"     "<<(lowest/trials)*100<<"%"<<"      "<<(lowest/trials)*100/firstrange<<endl;
    results<<firstrange<<"-"<<secondrange<<"   "<<(lower/trials)*100<<"%"<<"      "<<(lower/trials)*100/(secondrange-firstrange)<<endl;
    results<<secondrange<<"-"<<thirdrange<<"  "<<(low/trials)*100<<"%"<<"       "<<(low/trials)*100/(thirdrange-secondrange)<<endl;
    results<<thirdrange<<"-"<<fourthrange<<" "<<(middle/trials)*100<<"%"<<"       "<<(middle/trials)*100/(fourthrange-thirdrange)<<endl;
    results<<fourthrange<<"-"<<fifthrange<<" "<<(high/trials)*100<<"%"<<"       "<<(high/trials)*100/(fifthrange-fourthrange)<<endl;
    results<<fifthrange<<"-"<<sixthrange<<" "<<(higher/trials)*100<<"%"<<"       "<<(higher/trials)*100/(sixthrange-fifthrange)<<endl;
    results<<sixthrange<<"-"<<"    "<<(highest/trials)*100<<"%"<<"       "<<endl;
    results.close();



}

int main()
{   srand(time(NULL));

        mode1 active;
        active.sim();

}
