#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

//import csv file to "file"
ifstream file("5km_grid_combined_with_0to500dm_ngdc_vat.csv");


int main(){

    //outputdata is an array of vectors used to represent a table with GridID | SumCount | Sum(Count*depth)
    vector <int> outputdata[3];
    
    //skip first line of csv file (Skip Headers)
    string line;
    getline(file, line);



    //vector V is use to hold current line of csv file
    vector<int> v;



    
    //loop through csv file
    while (getline(file, line)){
        
        //clear vector
        v.clear();

        //get current line value and add it to sting line then convert to string stream
        stringstream ss(line); 

        //convert line into set of strings, store in vector V
        /* 
        v[1]=count
        v[2]= grid id
        v[3]=depth
        */
        while (ss.good()) { 
            string substr; 
            getline(ss, substr, ','); 
          
            v.push_back(stoi(substr)); 
        }

        //loop through table and either add to existing values or create new row
        
        for(int i=0;i<outputdata[0].size();i++){
         
            if((outputdata[0][i])==v[2]){
               
                (outputdata[1][i])+=(v[1]);
                (outputdata[2][i])+=((v[3])*(v[1]));
                //used to skip code to add a row
                goto skip;
                
            }
        }

        //if current gridID doesnt match any current then add new row
        outputdata[0].push_back(v[2]);
        outputdata[1].push_back(v[1]);
        outputdata[2].push_back(v[3]*v[1]);

        skip: 
         continue;          
    }  
  

    //create an open text file weighted means
    ofstream file_stream;                                                  
    file_stream.open ("WeightedMeans.txt");

    //code used to write all needed data to txt file
    file_stream<<setw(12)<<"Grid ID";
    file_stream<<setw(12)<<"Mean"<<endl;
    for(int i=0;i<outputdata[0].size();i++){
        file_stream<< setw(10)<<outputdata[0][i]<<"\t";
        file_stream<< setw(10)<<outputdata[1][i]<<"\t";
        file_stream<< setw(10)<<outputdata[2][i]<<"\t";
        cout.precision(7);
        cout << std::fixed;
        float weightedmean=((float)(outputdata[2][i])/(float)(outputdata[1][i]))/(float)10;
        file_stream<< setw(10)<<weightedmean<<endl;

    }

    //close file
   file_stream.close();
    
    return 0;
}