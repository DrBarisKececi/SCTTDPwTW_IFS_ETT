// Selective Clustered Tourist Trip Design Problem with Time Windows 
// Intuitionistic Fuzzy Objective 
// Stochastic Traveling Time
// Chance Constrained for Time Windows and Tmax

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NumberOfSets 250
#define NumberOfVertices 2000

// Fonksiyon prototip tanýmlarý
//------------------------------------------------------------------------------
void Reset_AllMatrices(void);
void Read_Information(char [],int);
int Control(int,int);

void Objective_Function(void);
void Fuzzy_Constraint(void);
void First_Constraint(void);
void Second_Constraint(void);
void Third_Constraint(void);
void Fourth_Constraint(void);
void Fifth_Constraint(void);
void Sixth_Constraint(void);
void Seventh_Constraint(void);
void Eighth_Constraint(void);
void Ninth_Constraint(void);
void Tenth_Constraint(void);
void Eleventh_Constraint(void);
void Twelfth_Constraint(void);
void Time_Constraint(void);
void Binaries(void);

// Global deðiþken tanýmlarý
//------------------------------------------------------------------------------
FILE *Information;
FILE *Write_Model;
FILE *Write_Command;
FILE *Read_MaxSolution;
FILE *Read_MinSolution;

int ClusterMatrix[NumberOfSets][NumberOfVertices];
long TimeMatrix[NumberOfVertices][NumberOfVertices];
long TimeWindow[NumberOfVertices][2];
long MaxSolution;
long MinSolution;

int NumberOfCustomer_InCluster[NumberOfSets];
int LimitofCustomerNumber_InCluster[NumberOfSets][2];

long Profit[NumberOfVertices];

int NumberOfCustomers;
int NumberOfClusters;

long TMax;
long FuzzyParameter_Min;
long FuzzyParameter_Vu;
long FuzzyParameter_Max;

double SecurityLevel;
double Value_ln;

// Ana fonksiyon
//------------------------------------------------------------------------------
int main()
{
          int Problem_Index;
          char ProblemName[1601][50] = {"" ,"3burma14_T40_P2_F1_SL10","3burma14_T40_P2_F1_SL20","3burma14_T40_P2_F1_SL30","3burma14_T40_P2_F1_SL40","3burma14_T40_P2_F1_SL50","3burma14_T40_P2_F1_SL60","3burma14_T40_P2_F1_SL70","3burma14_T40_P2_F1_SL80"
		  								   ,"3burma14_T60_P2_F1_SL10","3burma14_T60_P2_F1_SL20","3burma14_T60_P2_F1_SL30","3burma14_T60_P2_F1_SL40","3burma14_T60_P2_F1_SL50","3burma14_T60_P2_F1_SL60","3burma14_T60_P2_F1_SL70","3burma14_T60_P2_F1_SL80"
		  								   ,"3burma14_T80_P2_F1_SL10","3burma14_T80_P2_F1_SL20","3burma14_T80_P2_F1_SL30","3burma14_T80_P2_F1_SL40","3burma14_T80_P2_F1_SL50","3burma14_T80_P2_F1_SL60","3burma14_T80_P2_F1_SL70","3burma14_T80_P2_F1_SL80"
		  								   ,"3burma14_T100_P2_F1_SL10","3burma14_T100_P2_F1_SL20","3burma14_T100_P2_F1_SL30","3burma14_T100_P2_F1_SL40","3burma14_T100_P2_F1_SL50","3burma14_T100_P2_F1_SL60","3burma14_T100_P2_F1_SL70","3burma14_T100_P2_F1_SL80"
		  								  
		  								   ,"4gr17_T40_P2_F1_SL10","4gr17_T40_P2_F1_SL20","4gr17_T40_P2_F1_SL30","4gr17_T40_P2_F1_SL40","4gr17_T40_P2_F1_SL50","4gr17_T40_P2_F1_SL60","4gr17_T40_P2_F1_SL70","4gr17_T40_P2_F1_SL80"
		  								   ,"4gr17_T60_P2_F1_SL10","4gr17_T60_P2_F1_SL20","4gr17_T60_P2_F1_SL30","4gr17_T60_P2_F1_SL40","4gr17_T60_P2_F1_SL50","4gr17_T60_P2_F1_SL60","4gr17_T60_P2_F1_SL70","4gr17_T60_P2_F1_SL80"
		  								   ,"4gr17_T80_P2_F1_SL10","4gr17_T80_P2_F1_SL20","4gr17_T80_P2_F1_SL30","4gr17_T80_P2_F1_SL40","4gr17_T80_P2_F1_SL50","4gr17_T80_P2_F1_SL60","4gr17_T80_P2_F1_SL70","4gr17_T80_P2_F1_SL80"
		  								   ,"4gr17_T100_P2_F1_SL10","4gr17_T100_P2_F1_SL20","4gr17_T100_P2_F1_SL30","4gr17_T100_P2_F1_SL40","4gr17_T100_P2_F1_SL50","4gr17_T100_P2_F1_SL60","4gr17_T100_P2_F1_SL70","4gr17_T100_P2_F1_SL80"
		  								  
		  								   ,"4ulysses16_T40_P2_F1_SL10","4ulysses16_T40_P2_F1_SL20","4ulysses16_T40_P2_F1_SL30","4ulysses16_T40_P2_F1_SL40","4ulysses16_T40_P2_F1_SL50","4ulysses16_T40_P2_F1_SL60","4ulysses16_T40_P2_F1_SL70","4ulysses16_T40_P2_F1_SL80"
		  								   ,"4ulysses16_T60_P2_F1_SL10","4ulysses16_T60_P2_F1_SL20","4ulysses16_T60_P2_F1_SL30","4ulysses16_T60_P2_F1_SL40","4ulysses16_T60_P2_F1_SL50","4ulysses16_T60_P2_F1_SL60","4ulysses16_T60_P2_F1_SL70","4ulysses16_T60_P2_F1_SL80"
		  								   ,"4ulysses16_T80_P2_F1_SL10","4ulysses16_T80_P2_F1_SL20","4ulysses16_T80_P2_F1_SL30","4ulysses16_T80_P2_F1_SL40","4ulysses16_T80_P2_F1_SL50","4ulysses16_T80_P2_F1_SL60","4ulysses16_T80_P2_F1_SL70","4ulysses16_T80_P2_F1_SL80"
		  								   ,"4ulysses16_T100_P2_F1_SL10","4ulysses16_T100_P2_F1_SL20","4ulysses16_T100_P2_F1_SL30","4ulysses16_T100_P2_F1_SL40","4ulysses16_T100_P2_F1_SL50","4ulysses16_T100_P2_F1_SL60","4ulysses16_T100_P2_F1_SL70","4ulysses16_T100_P2_F1_SL80"
		  								  
		  								   ,"5gr21_T40_P2_F1_SL10","5gr21_T40_P2_F1_SL20","5gr21_T40_P2_F1_SL30","5gr21_T40_P2_F1_SL40","5gr21_T40_P2_F1_SL50","5gr21_T40_P2_F1_SL60","5gr21_T40_P2_F1_SL70","5gr21_T40_P2_F1_SL80"
		  								   ,"5gr21_T60_P2_F1_SL10","5gr21_T60_P2_F1_SL20","5gr21_T60_P2_F1_SL30","5gr21_T60_P2_F1_SL40","5gr21_T60_P2_F1_SL50","5gr21_T60_P2_F1_SL60","5gr21_T60_P2_F1_SL70","5gr21_T60_P2_F1_SL80"
		  								   ,"5gr21_T80_P2_F1_SL10","5gr21_T80_P2_F1_SL20","5gr21_T80_P2_F1_SL30","5gr21_T80_P2_F1_SL40","5gr21_T80_P2_F1_SL50","5gr21_T80_P2_F1_SL60","5gr21_T80_P2_F1_SL70","5gr21_T80_P2_F1_SL80"
		  								   ,"5gr21_T100_P2_F1_SL10","5gr21_T100_P2_F1_SL20","5gr21_T100_P2_F1_SL30","5gr21_T100_P2_F1_SL40","5gr21_T100_P2_F1_SL50","5gr21_T100_P2_F1_SL60","5gr21_T100_P2_F1_SL70","5gr21_T100_P2_F1_SL80"
		  								  
          								   ,"5gr24_T40_P2_F1_SL10","5gr24_T40_P2_F1_SL20","5gr24_T40_P2_F1_SL30","5gr24_T40_P2_F1_SL40","5gr24_T40_P2_F1_SL50","5gr24_T40_P2_F1_SL60","5gr24_T40_P2_F1_SL70","5gr24_T40_P2_F1_SL80"
		  								   ,"5gr24_T60_P2_F1_SL10","5gr24_T60_P2_F1_SL20","5gr24_T60_P2_F1_SL30","5gr24_T60_P2_F1_SL40","5gr24_T60_P2_F1_SL50","5gr24_T60_P2_F1_SL60","5gr24_T60_P2_F1_SL70","5gr24_T60_P2_F1_SL80"
		  								   ,"5gr24_T80_P2_F1_SL10","5gr24_T80_P2_F1_SL20","5gr24_T80_P2_F1_SL30","5gr24_T80_P2_F1_SL40","5gr24_T80_P2_F1_SL50","5gr24_T80_P2_F1_SL60","5gr24_T80_P2_F1_SL70","5gr24_T80_P2_F1_SL80"
		  								   ,"5gr24_T100_P2_F1_SL10","5gr24_T100_P2_F1_SL20","5gr24_T100_P2_F1_SL30","5gr24_T100_P2_F1_SL40","5gr24_T100_P2_F1_SL50","5gr24_T100_P2_F1_SL60","5gr24_T100_P2_F1_SL70","5gr24_T100_P2_F1_SL80"
		  								  
          								   ,"5ulysses22_T40_P2_F1_SL10","5ulysses22_T40_P2_F1_SL20","5ulysses22_T40_P2_F1_SL30","5ulysses22_T40_P2_F1_SL40","5ulysses22_T40_P2_F1_SL50","5ulysses22_T40_P2_F1_SL60","5ulysses22_T40_P2_F1_SL70","5ulysses22_T40_P2_F1_SL80"
		  								   ,"5ulysses22_T60_P2_F1_SL10","5ulysses22_T60_P2_F1_SL20","5ulysses22_T60_P2_F1_SL30","5ulysses22_T60_P2_F1_SL40","5ulysses22_T60_P2_F1_SL50","5ulysses22_T60_P2_F1_SL60","5ulysses22_T60_P2_F1_SL70","5ulysses22_T60_P2_F1_SL80"
		  								   ,"5ulysses22_T80_P2_F1_SL10","5ulysses22_T80_P2_F1_SL20","5ulysses22_T80_P2_F1_SL30","5ulysses22_T80_P2_F1_SL40","5ulysses22_T80_P2_F1_SL50","5ulysses22_T80_P2_F1_SL60","5ulysses22_T80_P2_F1_SL70","5ulysses22_T80_P2_F1_SL80"
		  								   ,"5ulysses22_T100_P2_F1_SL10","5ulysses22_T100_P2_F1_SL20","5ulysses22_T100_P2_F1_SL30","5ulysses22_T100_P2_F1_SL40","5ulysses22_T100_P2_F1_SL50","5ulysses22_T100_P2_F1_SL60","5ulysses22_T100_P2_F1_SL70","5ulysses22_T100_P2_F1_SL80"
		  								  
          								   ,"6bayg29_T40_P2_F1_SL10","6bayg29_T40_P2_F1_SL20","6bayg29_T40_P2_F1_SL30","6bayg29_T40_P2_F1_SL40","6bayg29_T40_P2_F1_SL50","6bayg29_T40_P2_F1_SL60","6bayg29_T40_P2_F1_SL70","6bayg29_T40_P2_F1_SL80"
		  								   ,"6bayg29_T60_P2_F1_SL10","6bayg29_T60_P2_F1_SL20","6bayg29_T60_P2_F1_SL30","6bayg29_T60_P2_F1_SL40","6bayg29_T60_P2_F1_SL50","6bayg29_T60_P2_F1_SL60","6bayg29_T60_P2_F1_SL70","6bayg29_T60_P2_F1_SL80"
		  								   ,"6bayg29_T80_P2_F1_SL10","6bayg29_T80_P2_F1_SL20","6bayg29_T80_P2_F1_SL30","6bayg29_T80_P2_F1_SL40","6bayg29_T80_P2_F1_SL50","6bayg29_T80_P2_F1_SL60","6bayg29_T80_P2_F1_SL70","6bayg29_T80_P2_F1_SL80"
		  								   ,"6bayg29_T100_P2_F1_SL10","6bayg29_T100_P2_F1_SL20","6bayg29_T100_P2_F1_SL30","6bayg29_T100_P2_F1_SL40","6bayg29_T100_P2_F1_SL50","6bayg29_T100_P2_F1_SL60","6bayg29_T100_P2_F1_SL70","6bayg29_T100_P2_F1_SL80"
		  								  
          								   ,"6bays29_T40_P2_F1_SL10","6bays29_T40_P2_F1_SL20","6bays29_T40_P2_F1_SL30","6bays29_T40_P2_F1_SL40","6bays29_T40_P2_F1_SL50","6bays29_T40_P2_F1_SL60","6bays29_T40_P2_F1_SL70","6bays29_T40_P2_F1_SL80"
		  								   ,"6bays29_T60_P2_F1_SL10","6bays29_T60_P2_F1_SL20","6bays29_T60_P2_F1_SL30","6bays29_T60_P2_F1_SL40","6bays29_T60_P2_F1_SL50","6bays29_T60_P2_F1_SL60","6bays29_T60_P2_F1_SL70","6bays29_T60_P2_F1_SL80"
		  								   ,"6bays29_T80_P2_F1_SL10","6bays29_T80_P2_F1_SL20","6bays29_T80_P2_F1_SL30","6bays29_T80_P2_F1_SL40","6bays29_T80_P2_F1_SL50","6bays29_T80_P2_F1_SL60","6bays29_T80_P2_F1_SL70","6bays29_T80_P2_F1_SL80"
		  								   ,"6bays29_T100_P2_F1_SL10","6bays29_T100_P2_F1_SL20","6bays29_T100_P2_F1_SL30","6bays29_T100_P2_F1_SL40","6bays29_T100_P2_F1_SL50","6bays29_T100_P2_F1_SL60","6bays29_T100_P2_F1_SL70","6bays29_T100_P2_F1_SL80"
		  								  
          								   ,"6fri26_T40_P2_F1_SL10","6fri26_T40_P2_F1_SL20","6fri26_T40_P2_F1_SL30","6fri26_T40_P2_F1_SL40","6fri26_T40_P2_F1_SL50","6fri26_T40_P2_F1_SL60","6fri26_T40_P2_F1_SL70","6fri26_T40_P2_F1_SL80"
		  								   ,"6fri26_T60_P2_F1_SL10","6fri26_T60_P2_F1_SL20","6fri26_T60_P2_F1_SL30","6fri26_T60_P2_F1_SL40","6fri26_T60_P2_F1_SL50","6fri26_T60_P2_F1_SL60","6fri26_T60_P2_F1_SL70","6fri26_T60_P2_F1_SL80"
		  								   ,"6fri26_T80_P2_F1_SL10","6fri26_T80_P2_F1_SL20","6fri26_T80_P2_F1_SL30","6fri26_T80_P2_F1_SL40","6fri26_T80_P2_F1_SL50","6fri26_T80_P2_F1_SL60","6fri26_T80_P2_F1_SL70","6fri26_T80_P2_F1_SL80"
		  								   ,"6fri26_T100_P2_F1_SL10","6fri26_T100_P2_F1_SL20","6fri26_T100_P2_F1_SL30","6fri26_T100_P2_F1_SL40","6fri26_T100_P2_F1_SL50","6fri26_T100_P2_F1_SL60","6fri26_T100_P2_F1_SL70","6fri26_T100_P2_F1_SL80"
		  								  
          								   ,"7ftv33_T40_P2_F1_SL10","7ftv33_T40_P2_F1_SL20","7ftv33_T40_P2_F1_SL30","7ftv33_T40_P2_F1_SL40","7ftv33_T40_P2_F1_SL50","7ftv33_T40_P2_F1_SL60","7ftv33_T40_P2_F1_SL70","7ftv33_T40_P2_F1_SL80"
		  								   ,"7ftv33_T60_P2_F1_SL10","7ftv33_T60_P2_F1_SL20","7ftv33_T60_P2_F1_SL30","7ftv33_T60_P2_F1_SL40","7ftv33_T60_P2_F1_SL50","7ftv33_T60_P2_F1_SL60","7ftv33_T60_P2_F1_SL70","7ftv33_T60_P2_F1_SL80"
		  								   ,"7ftv33_T80_P2_F1_SL10","7ftv33_T80_P2_F1_SL20","7ftv33_T80_P2_F1_SL30","7ftv33_T80_P2_F1_SL40","7ftv33_T80_P2_F1_SL50","7ftv33_T80_P2_F1_SL60","7ftv33_T80_P2_F1_SL70","7ftv33_T80_P2_F1_SL80"
		  								   ,"7ftv33_T100_P2_F1_SL10","7ftv33_T100_P2_F1_SL20","7ftv33_T100_P2_F1_SL30","7ftv33_T100_P2_F1_SL40","7ftv33_T100_P2_F1_SL50","7ftv33_T100_P2_F1_SL60","7ftv33_T100_P2_F1_SL70","7ftv33_T100_P2_F1_SL80"
          
          								   ,"3burma14_T40_P2_F2_SL10","3burma14_T40_P2_F2_SL20","3burma14_T40_P2_F2_SL30","3burma14_T40_P2_F2_SL40","3burma14_T40_P2_F2_SL50","3burma14_T40_P2_F2_SL60","3burma14_T40_P2_F2_SL70","3burma14_T40_P2_F2_SL80"
		  								   ,"3burma14_T60_P2_F2_SL10","3burma14_T60_P2_F2_SL20","3burma14_T60_P2_F2_SL30","3burma14_T60_P2_F2_SL40","3burma14_T60_P2_F2_SL50","3burma14_T60_P2_F2_SL60","3burma14_T60_P2_F2_SL70","3burma14_T60_P2_F2_SL80"
		  								   ,"3burma14_T80_P2_F2_SL10","3burma14_T80_P2_F2_SL20","3burma14_T80_P2_F2_SL30","3burma14_T80_P2_F2_SL40","3burma14_T80_P2_F2_SL50","3burma14_T80_P2_F2_SL60","3burma14_T80_P2_F2_SL70","3burma14_T80_P2_F2_SL80"
		  								   ,"3burma14_T100_P2_F2_SL10","3burma14_T100_P2_F2_SL20","3burma14_T100_P2_F2_SL30","3burma14_T100_P2_F2_SL40","3burma14_T100_P2_F2_SL50","3burma14_T100_P2_F2_SL60","3burma14_T100_P2_F2_SL70","3burma14_T100_P2_F2_SL80"
		  								  
		  								   ,"4gr17_T40_P2_F2_SL10","4gr17_T40_P2_F2_SL20","4gr17_T40_P2_F2_SL30","4gr17_T40_P2_F2_SL40","4gr17_T40_P2_F2_SL50","4gr17_T40_P2_F2_SL60","4gr17_T40_P2_F2_SL70","4gr17_T40_P2_F2_SL80"
		  								   ,"4gr17_T60_P2_F2_SL10","4gr17_T60_P2_F2_SL20","4gr17_T60_P2_F2_SL30","4gr17_T60_P2_F2_SL40","4gr17_T60_P2_F2_SL50","4gr17_T60_P2_F2_SL60","4gr17_T60_P2_F2_SL70","4gr17_T60_P2_F2_SL80"
		  								   ,"4gr17_T80_P2_F2_SL10","4gr17_T80_P2_F2_SL20","4gr17_T80_P2_F2_SL30","4gr17_T80_P2_F2_SL40","4gr17_T80_P2_F2_SL50","4gr17_T80_P2_F2_SL60","4gr17_T80_P2_F2_SL70","4gr17_T80_P2_F2_SL80"
		  								   ,"4gr17_T100_P2_F2_SL10","4gr17_T100_P2_F2_SL20","4gr17_T100_P2_F2_SL30","4gr17_T100_P2_F2_SL40","4gr17_T100_P2_F2_SL50","4gr17_T100_P2_F2_SL60","4gr17_T100_P2_F2_SL70","4gr17_T100_P2_F2_SL80"
		  								  
		  								   ,"4ulysses16_T40_P2_F2_SL10","4ulysses16_T40_P2_F2_SL20","4ulysses16_T40_P2_F2_SL30","4ulysses16_T40_P2_F2_SL40","4ulysses16_T40_P2_F2_SL50","4ulysses16_T40_P2_F2_SL60","4ulysses16_T40_P2_F2_SL70","4ulysses16_T40_P2_F2_SL80"
		  								   ,"4ulysses16_T60_P2_F2_SL10","4ulysses16_T60_P2_F2_SL20","4ulysses16_T60_P2_F2_SL30","4ulysses16_T60_P2_F2_SL40","4ulysses16_T60_P2_F2_SL50","4ulysses16_T60_P2_F2_SL60","4ulysses16_T60_P2_F2_SL70","4ulysses16_T60_P2_F2_SL80"
		  								   ,"4ulysses16_T80_P2_F2_SL10","4ulysses16_T80_P2_F2_SL20","4ulysses16_T80_P2_F2_SL30","4ulysses16_T80_P2_F2_SL40","4ulysses16_T80_P2_F2_SL50","4ulysses16_T80_P2_F2_SL60","4ulysses16_T80_P2_F2_SL70","4ulysses16_T80_P2_F2_SL80"
		  								   ,"4ulysses16_T100_P2_F2_SL10","4ulysses16_T100_P2_F2_SL20","4ulysses16_T100_P2_F2_SL30","4ulysses16_T100_P2_F2_SL40","4ulysses16_T100_P2_F2_SL50","4ulysses16_T100_P2_F2_SL60","4ulysses16_T100_P2_F2_SL70","4ulysses16_T100_P2_F2_SL80"
		  								  
		  								   ,"5gr21_T40_P2_F2_SL10","5gr21_T40_P2_F2_SL20","5gr21_T40_P2_F2_SL30","5gr21_T40_P2_F2_SL40","5gr21_T40_P2_F2_SL50","5gr21_T40_P2_F2_SL60","5gr21_T40_P2_F2_SL70","5gr21_T40_P2_F2_SL80"
		  								   ,"5gr21_T60_P2_F2_SL10","5gr21_T60_P2_F2_SL20","5gr21_T60_P2_F2_SL30","5gr21_T60_P2_F2_SL40","5gr21_T60_P2_F2_SL50","5gr21_T60_P2_F2_SL60","5gr21_T60_P2_F2_SL70","5gr21_T60_P2_F2_SL80"
		  								   ,"5gr21_T80_P2_F2_SL10","5gr21_T80_P2_F2_SL20","5gr21_T80_P2_F2_SL30","5gr21_T80_P2_F2_SL40","5gr21_T80_P2_F2_SL50","5gr21_T80_P2_F2_SL60","5gr21_T80_P2_F2_SL70","5gr21_T80_P2_F2_SL80"
		  								   ,"5gr21_T100_P2_F2_SL10","5gr21_T100_P2_F2_SL20","5gr21_T100_P2_F2_SL30","5gr21_T100_P2_F2_SL40","5gr21_T100_P2_F2_SL50","5gr21_T100_P2_F2_SL60","5gr21_T100_P2_F2_SL70","5gr21_T100_P2_F2_SL80"
		  								  
          								   ,"5gr24_T40_P2_F2_SL10","5gr24_T40_P2_F2_SL20","5gr24_T40_P2_F2_SL30","5gr24_T40_P2_F2_SL40","5gr24_T40_P2_F2_SL50","5gr24_T40_P2_F2_SL60","5gr24_T40_P2_F2_SL70","5gr24_T40_P2_F2_SL80"
		  								   ,"5gr24_T60_P2_F2_SL10","5gr24_T60_P2_F2_SL20","5gr24_T60_P2_F2_SL30","5gr24_T60_P2_F2_SL40","5gr24_T60_P2_F2_SL50","5gr24_T60_P2_F2_SL60","5gr24_T60_P2_F2_SL70","5gr24_T60_P2_F2_SL80"
		  								   ,"5gr24_T80_P2_F2_SL10","5gr24_T80_P2_F2_SL20","5gr24_T80_P2_F2_SL30","5gr24_T80_P2_F2_SL40","5gr24_T80_P2_F2_SL50","5gr24_T80_P2_F2_SL60","5gr24_T80_P2_F2_SL70","5gr24_T80_P2_F2_SL80"
		  								   ,"5gr24_T100_P2_F2_SL10","5gr24_T100_P2_F2_SL20","5gr24_T100_P2_F2_SL30","5gr24_T100_P2_F2_SL40","5gr24_T100_P2_F2_SL50","5gr24_T100_P2_F2_SL60","5gr24_T100_P2_F2_SL70","5gr24_T100_P2_F2_SL80"
		  								  
          								   ,"5ulysses22_T40_P2_F2_SL10","5ulysses22_T40_P2_F2_SL20","5ulysses22_T40_P2_F2_SL30","5ulysses22_T40_P2_F2_SL40","5ulysses22_T40_P2_F2_SL50","5ulysses22_T40_P2_F2_SL60","5ulysses22_T40_P2_F2_SL70","5ulysses22_T40_P2_F2_SL80"
		  								   ,"5ulysses22_T60_P2_F2_SL10","5ulysses22_T60_P2_F2_SL20","5ulysses22_T60_P2_F2_SL30","5ulysses22_T60_P2_F2_SL40","5ulysses22_T60_P2_F2_SL50","5ulysses22_T60_P2_F2_SL60","5ulysses22_T60_P2_F2_SL70","5ulysses22_T60_P2_F2_SL80"
		  								   ,"5ulysses22_T80_P2_F2_SL10","5ulysses22_T80_P2_F2_SL20","5ulysses22_T80_P2_F2_SL30","5ulysses22_T80_P2_F2_SL40","5ulysses22_T80_P2_F2_SL50","5ulysses22_T80_P2_F2_SL60","5ulysses22_T80_P2_F2_SL70","5ulysses22_T80_P2_F2_SL80"
		  								   ,"5ulysses22_T100_P2_F2_SL10","5ulysses22_T100_P2_F2_SL20","5ulysses22_T100_P2_F2_SL30","5ulysses22_T100_P2_F2_SL40","5ulysses22_T100_P2_F2_SL50","5ulysses22_T100_P2_F2_SL60","5ulysses22_T100_P2_F2_SL70","5ulysses22_T100_P2_F2_SL80"
		  								  
          								   ,"6bayg29_T40_P2_F2_SL10","6bayg29_T40_P2_F2_SL20","6bayg29_T40_P2_F2_SL30","6bayg29_T40_P2_F2_SL40","6bayg29_T40_P2_F2_SL50","6bayg29_T40_P2_F2_SL60","6bayg29_T40_P2_F2_SL70","6bayg29_T40_P2_F2_SL80"
		  								   ,"6bayg29_T60_P2_F2_SL10","6bayg29_T60_P2_F2_SL20","6bayg29_T60_P2_F2_SL30","6bayg29_T60_P2_F2_SL40","6bayg29_T60_P2_F2_SL50","6bayg29_T60_P2_F2_SL60","6bayg29_T60_P2_F2_SL70","6bayg29_T60_P2_F2_SL80"
		  								   ,"6bayg29_T80_P2_F2_SL10","6bayg29_T80_P2_F2_SL20","6bayg29_T80_P2_F2_SL30","6bayg29_T80_P2_F2_SL40","6bayg29_T80_P2_F2_SL50","6bayg29_T80_P2_F2_SL60","6bayg29_T80_P2_F2_SL70","6bayg29_T80_P2_F2_SL80"
		  								   ,"6bayg29_T100_P2_F2_SL10","6bayg29_T100_P2_F2_SL20","6bayg29_T100_P2_F2_SL30","6bayg29_T100_P2_F2_SL40","6bayg29_T100_P2_F2_SL50","6bayg29_T100_P2_F2_SL60","6bayg29_T100_P2_F2_SL70","6bayg29_T100_P2_F2_SL80"
		  								  
          								   ,"6bays29_T40_P2_F2_SL10","6bays29_T40_P2_F2_SL20","6bays29_T40_P2_F2_SL30","6bays29_T40_P2_F2_SL40","6bays29_T40_P2_F2_SL50","6bays29_T40_P2_F2_SL60","6bays29_T40_P2_F2_SL70","6bays29_T40_P2_F2_SL80"
		  								   ,"6bays29_T60_P2_F2_SL10","6bays29_T60_P2_F2_SL20","6bays29_T60_P2_F2_SL30","6bays29_T60_P2_F2_SL40","6bays29_T60_P2_F2_SL50","6bays29_T60_P2_F2_SL60","6bays29_T60_P2_F2_SL70","6bays29_T60_P2_F2_SL80"
		  								   ,"6bays29_T80_P2_F2_SL10","6bays29_T80_P2_F2_SL20","6bays29_T80_P2_F2_SL30","6bays29_T80_P2_F2_SL40","6bays29_T80_P2_F2_SL50","6bays29_T80_P2_F2_SL60","6bays29_T80_P2_F2_SL70","6bays29_T80_P2_F2_SL80"
		  								   ,"6bays29_T100_P2_F2_SL10","6bays29_T100_P2_F2_SL20","6bays29_T100_P2_F2_SL30","6bays29_T100_P2_F2_SL40","6bays29_T100_P2_F2_SL50","6bays29_T100_P2_F2_SL60","6bays29_T100_P2_F2_SL70","6bays29_T100_P2_F2_SL80"
		  								  
          								   ,"6fri26_T40_P2_F2_SL10","6fri26_T40_P2_F2_SL20","6fri26_T40_P2_F2_SL30","6fri26_T40_P2_F2_SL40","6fri26_T40_P2_F2_SL50","6fri26_T40_P2_F2_SL60","6fri26_T40_P2_F2_SL70","6fri26_T40_P2_F2_SL80"
		  								   ,"6fri26_T60_P2_F2_SL10","6fri26_T60_P2_F2_SL20","6fri26_T60_P2_F2_SL30","6fri26_T60_P2_F2_SL40","6fri26_T60_P2_F2_SL50","6fri26_T60_P2_F2_SL60","6fri26_T60_P2_F2_SL70","6fri26_T60_P2_F2_SL80"
		  								   ,"6fri26_T80_P2_F2_SL10","6fri26_T80_P2_F2_SL20","6fri26_T80_P2_F2_SL30","6fri26_T80_P2_F2_SL40","6fri26_T80_P2_F2_SL50","6fri26_T80_P2_F2_SL60","6fri26_T80_P2_F2_SL70","6fri26_T80_P2_F2_SL80"
		  								   ,"6fri26_T100_P2_F2_SL10","6fri26_T100_P2_F2_SL20","6fri26_T100_P2_F2_SL30","6fri26_T100_P2_F2_SL40","6fri26_T100_P2_F2_SL50","6fri26_T100_P2_F2_SL60","6fri26_T100_P2_F2_SL70","6fri26_T100_P2_F2_SL80"
		  								  
          								   ,"7ftv33_T40_P2_F2_SL10","7ftv33_T40_P2_F2_SL20","7ftv33_T40_P2_F2_SL30","7ftv33_T40_P2_F2_SL40","7ftv33_T40_P2_F2_SL50","7ftv33_T40_P2_F2_SL60","7ftv33_T40_P2_F2_SL70","7ftv33_T40_P2_F2_SL80"
		  								   ,"7ftv33_T60_P2_F2_SL10","7ftv33_T60_P2_F2_SL20","7ftv33_T60_P2_F2_SL30","7ftv33_T60_P2_F2_SL40","7ftv33_T60_P2_F2_SL50","7ftv33_T60_P2_F2_SL60","7ftv33_T60_P2_F2_SL70","7ftv33_T60_P2_F2_SL80"
		  								   ,"7ftv33_T80_P2_F2_SL10","7ftv33_T80_P2_F2_SL20","7ftv33_T80_P2_F2_SL30","7ftv33_T80_P2_F2_SL40","7ftv33_T80_P2_F2_SL50","7ftv33_T80_P2_F2_SL60","7ftv33_T80_P2_F2_SL70","7ftv33_T80_P2_F2_SL80"
		  								   ,"7ftv33_T100_P2_F2_SL10","7ftv33_T100_P2_F2_SL20","7ftv33_T100_P2_F2_SL30","7ftv33_T100_P2_F2_SL40","7ftv33_T100_P2_F2_SL50","7ftv33_T100_P2_F2_SL60","7ftv33_T100_P2_F2_SL70","7ftv33_T100_P2_F2_SL80"
          
          								   ,"3burma14_T40_P2_F3_SL10","3burma14_T40_P2_F3_SL20","3burma14_T40_P2_F3_SL30","3burma14_T40_P2_F3_SL40","3burma14_T40_P2_F3_SL50","3burma14_T40_P2_F3_SL60","3burma14_T40_P2_F3_SL70","3burma14_T40_P2_F3_SL80"
		  								   ,"3burma14_T60_P2_F3_SL10","3burma14_T60_P2_F3_SL20","3burma14_T60_P2_F3_SL30","3burma14_T60_P2_F3_SL40","3burma14_T60_P2_F3_SL50","3burma14_T60_P2_F3_SL60","3burma14_T60_P2_F3_SL70","3burma14_T60_P2_F3_SL80"
		  								   ,"3burma14_T80_P2_F3_SL10","3burma14_T80_P2_F3_SL20","3burma14_T80_P2_F3_SL30","3burma14_T80_P2_F3_SL40","3burma14_T80_P2_F3_SL50","3burma14_T80_P2_F3_SL60","3burma14_T80_P2_F3_SL70","3burma14_T80_P2_F3_SL80"
		  								   ,"3burma14_T100_P2_F3_SL10","3burma14_T100_P2_F3_SL20","3burma14_T100_P2_F3_SL30","3burma14_T100_P2_F3_SL40","3burma14_T100_P2_F3_SL50","3burma14_T100_P2_F3_SL60","3burma14_T100_P2_F3_SL70","3burma14_T100_P2_F3_SL80"
		  								  
		  								   ,"4gr17_T40_P2_F3_SL10","4gr17_T40_P2_F3_SL20","4gr17_T40_P2_F3_SL30","4gr17_T40_P2_F3_SL40","4gr17_T40_P2_F3_SL50","4gr17_T40_P2_F3_SL60","4gr17_T40_P2_F3_SL70","4gr17_T40_P2_F3_SL80"
		  								   ,"4gr17_T60_P2_F3_SL10","4gr17_T60_P2_F3_SL20","4gr17_T60_P2_F3_SL30","4gr17_T60_P2_F3_SL40","4gr17_T60_P2_F3_SL50","4gr17_T60_P2_F3_SL60","4gr17_T60_P2_F3_SL70","4gr17_T60_P2_F3_SL80"
		  								   ,"4gr17_T80_P2_F3_SL10","4gr17_T80_P2_F3_SL20","4gr17_T80_P2_F3_SL30","4gr17_T80_P2_F3_SL40","4gr17_T80_P2_F3_SL50","4gr17_T80_P2_F3_SL60","4gr17_T80_P2_F3_SL70","4gr17_T80_P2_F3_SL80"
		  								   ,"4gr17_T100_P2_F3_SL10","4gr17_T100_P2_F3_SL20","4gr17_T100_P2_F3_SL30","4gr17_T100_P2_F3_SL40","4gr17_T100_P2_F3_SL50","4gr17_T100_P2_F3_SL60","4gr17_T100_P2_F3_SL70","4gr17_T100_P2_F3_SL80"
		  								  
		  								   ,"4ulysses16_T40_P2_F3_SL10","4ulysses16_T40_P2_F3_SL20","4ulysses16_T40_P2_F3_SL30","4ulysses16_T40_P2_F3_SL40","4ulysses16_T40_P2_F3_SL50","4ulysses16_T40_P2_F3_SL60","4ulysses16_T40_P2_F3_SL70","4ulysses16_T40_P2_F3_SL80"
		  								   ,"4ulysses16_T60_P2_F3_SL10","4ulysses16_T60_P2_F3_SL20","4ulysses16_T60_P2_F3_SL30","4ulysses16_T60_P2_F3_SL40","4ulysses16_T60_P2_F3_SL50","4ulysses16_T60_P2_F3_SL60","4ulysses16_T60_P2_F3_SL70","4ulysses16_T60_P2_F3_SL80"
		  								   ,"4ulysses16_T80_P2_F3_SL10","4ulysses16_T80_P2_F3_SL20","4ulysses16_T80_P2_F3_SL30","4ulysses16_T80_P2_F3_SL40","4ulysses16_T80_P2_F3_SL50","4ulysses16_T80_P2_F3_SL60","4ulysses16_T80_P2_F3_SL70","4ulysses16_T80_P2_F3_SL80"
		  								   ,"4ulysses16_T100_P2_F3_SL10","4ulysses16_T100_P2_F3_SL20","4ulysses16_T100_P2_F3_SL30","4ulysses16_T100_P2_F3_SL40","4ulysses16_T100_P2_F3_SL50","4ulysses16_T100_P2_F3_SL60","4ulysses16_T100_P2_F3_SL70","4ulysses16_T100_P2_F3_SL80"
		  								  
		  								   ,"5gr21_T40_P2_F3_SL10","5gr21_T40_P2_F3_SL20","5gr21_T40_P2_F3_SL30","5gr21_T40_P2_F3_SL40","5gr21_T40_P2_F3_SL50","5gr21_T40_P2_F3_SL60","5gr21_T40_P2_F3_SL70","5gr21_T40_P2_F3_SL80"
		  								   ,"5gr21_T60_P2_F3_SL10","5gr21_T60_P2_F3_SL20","5gr21_T60_P2_F3_SL30","5gr21_T60_P2_F3_SL40","5gr21_T60_P2_F3_SL50","5gr21_T60_P2_F3_SL60","5gr21_T60_P2_F3_SL70","5gr21_T60_P2_F3_SL80"
		  								   ,"5gr21_T80_P2_F3_SL10","5gr21_T80_P2_F3_SL20","5gr21_T80_P2_F3_SL30","5gr21_T80_P2_F3_SL40","5gr21_T80_P2_F3_SL50","5gr21_T80_P2_F3_SL60","5gr21_T80_P2_F3_SL70","5gr21_T80_P2_F3_SL80"
		  								   ,"5gr21_T100_P2_F3_SL10","5gr21_T100_P2_F3_SL20","5gr21_T100_P2_F3_SL30","5gr21_T100_P2_F3_SL40","5gr21_T100_P2_F3_SL50","5gr21_T100_P2_F3_SL60","5gr21_T100_P2_F3_SL70","5gr21_T100_P2_F3_SL80"
		  								  
          								   ,"5gr24_T40_P2_F3_SL10","5gr24_T40_P2_F3_SL20","5gr24_T40_P2_F3_SL30","5gr24_T40_P2_F3_SL40","5gr24_T40_P2_F3_SL50","5gr24_T40_P2_F3_SL60","5gr24_T40_P2_F3_SL70","5gr24_T40_P2_F3_SL80"
		  								   ,"5gr24_T60_P2_F3_SL10","5gr24_T60_P2_F3_SL20","5gr24_T60_P2_F3_SL30","5gr24_T60_P2_F3_SL40","5gr24_T60_P2_F3_SL50","5gr24_T60_P2_F3_SL60","5gr24_T60_P2_F3_SL70","5gr24_T60_P2_F3_SL80"
		  								   ,"5gr24_T80_P2_F3_SL10","5gr24_T80_P2_F3_SL20","5gr24_T80_P2_F3_SL30","5gr24_T80_P2_F3_SL40","5gr24_T80_P2_F3_SL50","5gr24_T80_P2_F3_SL60","5gr24_T80_P2_F3_SL70","5gr24_T80_P2_F3_SL80"
		  								   ,"5gr24_T100_P2_F3_SL10","5gr24_T100_P2_F3_SL20","5gr24_T100_P2_F3_SL30","5gr24_T100_P2_F3_SL40","5gr24_T100_P2_F3_SL50","5gr24_T100_P2_F3_SL60","5gr24_T100_P2_F3_SL70","5gr24_T100_P2_F3_SL80"
		  								  
          								   ,"5ulysses22_T40_P2_F3_SL10","5ulysses22_T40_P2_F3_SL20","5ulysses22_T40_P2_F3_SL30","5ulysses22_T40_P2_F3_SL40","5ulysses22_T40_P2_F3_SL50","5ulysses22_T40_P2_F3_SL60","5ulysses22_T40_P2_F3_SL70","5ulysses22_T40_P2_F3_SL80"
		  								   ,"5ulysses22_T60_P2_F3_SL10","5ulysses22_T60_P2_F3_SL20","5ulysses22_T60_P2_F3_SL30","5ulysses22_T60_P2_F3_SL40","5ulysses22_T60_P2_F3_SL50","5ulysses22_T60_P2_F3_SL60","5ulysses22_T60_P2_F3_SL70","5ulysses22_T60_P2_F3_SL80"
		  								   ,"5ulysses22_T80_P2_F3_SL10","5ulysses22_T80_P2_F3_SL20","5ulysses22_T80_P2_F3_SL30","5ulysses22_T80_P2_F3_SL40","5ulysses22_T80_P2_F3_SL50","5ulysses22_T80_P2_F3_SL60","5ulysses22_T80_P2_F3_SL70","5ulysses22_T80_P2_F3_SL80"
		  								   ,"5ulysses22_T100_P2_F3_SL10","5ulysses22_T100_P2_F3_SL20","5ulysses22_T100_P2_F3_SL30","5ulysses22_T100_P2_F3_SL40","5ulysses22_T100_P2_F3_SL50","5ulysses22_T100_P2_F3_SL60","5ulysses22_T100_P2_F3_SL70","5ulysses22_T100_P2_F3_SL80"
		  								  
          								   ,"6bayg29_T40_P2_F3_SL10","6bayg29_T40_P2_F3_SL20","6bayg29_T40_P2_F3_SL30","6bayg29_T40_P2_F3_SL40","6bayg29_T40_P2_F3_SL50","6bayg29_T40_P2_F3_SL60","6bayg29_T40_P2_F3_SL70","6bayg29_T40_P2_F3_SL80"
		  								   ,"6bayg29_T60_P2_F3_SL10","6bayg29_T60_P2_F3_SL20","6bayg29_T60_P2_F3_SL30","6bayg29_T60_P2_F3_SL40","6bayg29_T60_P2_F3_SL50","6bayg29_T60_P2_F3_SL60","6bayg29_T60_P2_F3_SL70","6bayg29_T60_P2_F3_SL80"
		  								   ,"6bayg29_T80_P2_F3_SL10","6bayg29_T80_P2_F3_SL20","6bayg29_T80_P2_F3_SL30","6bayg29_T80_P2_F3_SL40","6bayg29_T80_P2_F3_SL50","6bayg29_T80_P2_F3_SL60","6bayg29_T80_P2_F3_SL70","6bayg29_T80_P2_F3_SL80"
		  								   ,"6bayg29_T100_P2_F3_SL10","6bayg29_T100_P2_F3_SL20","6bayg29_T100_P2_F3_SL30","6bayg29_T100_P2_F3_SL40","6bayg29_T100_P2_F3_SL50","6bayg29_T100_P2_F3_SL60","6bayg29_T100_P2_F3_SL70","6bayg29_T100_P2_F3_SL80"
		  								  
          								   ,"6bays29_T40_P2_F3_SL10","6bays29_T40_P2_F3_SL20","6bays29_T40_P2_F3_SL30","6bays29_T40_P2_F3_SL40","6bays29_T40_P2_F3_SL50","6bays29_T40_P2_F3_SL60","6bays29_T40_P2_F3_SL70","6bays29_T40_P2_F3_SL80"
		  								   ,"6bays29_T60_P2_F3_SL10","6bays29_T60_P2_F3_SL20","6bays29_T60_P2_F3_SL30","6bays29_T60_P2_F3_SL40","6bays29_T60_P2_F3_SL50","6bays29_T60_P2_F3_SL60","6bays29_T60_P2_F3_SL70","6bays29_T60_P2_F3_SL80"
		  								   ,"6bays29_T80_P2_F3_SL10","6bays29_T80_P2_F3_SL20","6bays29_T80_P2_F3_SL30","6bays29_T80_P2_F3_SL40","6bays29_T80_P2_F3_SL50","6bays29_T80_P2_F3_SL60","6bays29_T80_P2_F3_SL70","6bays29_T80_P2_F3_SL80"
		  								   ,"6bays29_T100_P2_F3_SL10","6bays29_T100_P2_F3_SL20","6bays29_T100_P2_F3_SL30","6bays29_T100_P2_F3_SL40","6bays29_T100_P2_F3_SL50","6bays29_T100_P2_F3_SL60","6bays29_T100_P2_F3_SL70","6bays29_T100_P2_F3_SL80"
		  								  
          								   ,"6fri26_T40_P2_F3_SL10","6fri26_T40_P2_F3_SL20","6fri26_T40_P2_F3_SL30","6fri26_T40_P2_F3_SL40","6fri26_T40_P2_F3_SL50","6fri26_T40_P2_F3_SL60","6fri26_T40_P2_F3_SL70","6fri26_T40_P2_F3_SL80"
		  								   ,"6fri26_T60_P2_F3_SL10","6fri26_T60_P2_F3_SL20","6fri26_T60_P2_F3_SL30","6fri26_T60_P2_F3_SL40","6fri26_T60_P2_F3_SL50","6fri26_T60_P2_F3_SL60","6fri26_T60_P2_F3_SL70","6fri26_T60_P2_F3_SL80"
		  								   ,"6fri26_T80_P2_F3_SL10","6fri26_T80_P2_F3_SL20","6fri26_T80_P2_F3_SL30","6fri26_T80_P2_F3_SL40","6fri26_T80_P2_F3_SL50","6fri26_T80_P2_F3_SL60","6fri26_T80_P2_F3_SL70","6fri26_T80_P2_F3_SL80"
		  								   ,"6fri26_T100_P2_F3_SL10","6fri26_T100_P2_F3_SL20","6fri26_T100_P2_F3_SL30","6fri26_T100_P2_F3_SL40","6fri26_T100_P2_F3_SL50","6fri26_T100_P2_F3_SL60","6fri26_T100_P2_F3_SL70","6fri26_T100_P2_F3_SL80"
		  								  
          								   ,"7ftv33_T40_P2_F3_SL10","7ftv33_T40_P2_F3_SL20","7ftv33_T40_P2_F3_SL30","7ftv33_T40_P2_F3_SL40","7ftv33_T40_P2_F3_SL50","7ftv33_T40_P2_F3_SL60","7ftv33_T40_P2_F3_SL70","7ftv33_T40_P2_F3_SL80"
		  								   ,"7ftv33_T60_P2_F3_SL10","7ftv33_T60_P2_F3_SL20","7ftv33_T60_P2_F3_SL30","7ftv33_T60_P2_F3_SL40","7ftv33_T60_P2_F3_SL50","7ftv33_T60_P2_F3_SL60","7ftv33_T60_P2_F3_SL70","7ftv33_T60_P2_F3_SL80"
		  								   ,"7ftv33_T80_P2_F3_SL10","7ftv33_T80_P2_F3_SL20","7ftv33_T80_P2_F3_SL30","7ftv33_T80_P2_F3_SL40","7ftv33_T80_P2_F3_SL50","7ftv33_T80_P2_F3_SL60","7ftv33_T80_P2_F3_SL70","7ftv33_T80_P2_F3_SL80"
		  								   ,"7ftv33_T100_P2_F3_SL10","7ftv33_T100_P2_F3_SL20","7ftv33_T100_P2_F3_SL30","7ftv33_T100_P2_F3_SL40","7ftv33_T100_P2_F3_SL50","7ftv33_T100_P2_F3_SL60","7ftv33_T100_P2_F3_SL70","7ftv33_T100_P2_F3_SL80"
          
          								   ,"3burma14_T40_P2_F4_SL10","3burma14_T40_P2_F4_SL20","3burma14_T40_P2_F4_SL30","3burma14_T40_P2_F4_SL40","3burma14_T40_P2_F4_SL50","3burma14_T40_P2_F4_SL60","3burma14_T40_P2_F4_SL70","3burma14_T40_P2_F4_SL80"
		  								   ,"3burma14_T60_P2_F4_SL10","3burma14_T60_P2_F4_SL20","3burma14_T60_P2_F4_SL30","3burma14_T60_P2_F4_SL40","3burma14_T60_P2_F4_SL50","3burma14_T60_P2_F4_SL60","3burma14_T60_P2_F4_SL70","3burma14_T60_P2_F4_SL80"
		  								   ,"3burma14_T80_P2_F4_SL10","3burma14_T80_P2_F4_SL20","3burma14_T80_P2_F4_SL30","3burma14_T80_P2_F4_SL40","3burma14_T80_P2_F4_SL50","3burma14_T80_P2_F4_SL60","3burma14_T80_P2_F4_SL70","3burma14_T80_P2_F4_SL80"
		  								   ,"3burma14_T100_P2_F4_SL10","3burma14_T100_P2_F4_SL20","3burma14_T100_P2_F4_SL30","3burma14_T100_P2_F4_SL40","3burma14_T100_P2_F4_SL50","3burma14_T100_P2_F4_SL60","3burma14_T100_P2_F4_SL70","3burma14_T100_P2_F4_SL80"
		  								  
		  								   ,"4gr17_T40_P2_F4_SL10","4gr17_T40_P2_F4_SL20","4gr17_T40_P2_F4_SL30","4gr17_T40_P2_F4_SL40","4gr17_T40_P2_F4_SL50","4gr17_T40_P2_F4_SL60","4gr17_T40_P2_F4_SL70","4gr17_T40_P2_F4_SL80"
		  								   ,"4gr17_T60_P2_F4_SL10","4gr17_T60_P2_F4_SL20","4gr17_T60_P2_F4_SL30","4gr17_T60_P2_F4_SL40","4gr17_T60_P2_F4_SL50","4gr17_T60_P2_F4_SL60","4gr17_T60_P2_F4_SL70","4gr17_T60_P2_F4_SL80"
		  								   ,"4gr17_T80_P2_F4_SL10","4gr17_T80_P2_F4_SL20","4gr17_T80_P2_F4_SL30","4gr17_T80_P2_F4_SL40","4gr17_T80_P2_F4_SL50","4gr17_T80_P2_F4_SL60","4gr17_T80_P2_F4_SL70","4gr17_T80_P2_F4_SL80"
		  								   ,"4gr17_T100_P2_F4_SL10","4gr17_T100_P2_F4_SL20","4gr17_T100_P2_F4_SL30","4gr17_T100_P2_F4_SL40","4gr17_T100_P2_F4_SL50","4gr17_T100_P2_F4_SL60","4gr17_T100_P2_F4_SL70","4gr17_T100_P2_F4_SL80"
		  								  
		  								   ,"4ulysses16_T40_P2_F4_SL10","4ulysses16_T40_P2_F4_SL20","4ulysses16_T40_P2_F4_SL30","4ulysses16_T40_P2_F4_SL40","4ulysses16_T40_P2_F4_SL50","4ulysses16_T40_P2_F4_SL60","4ulysses16_T40_P2_F4_SL70","4ulysses16_T40_P2_F4_SL80"
		  								   ,"4ulysses16_T60_P2_F4_SL10","4ulysses16_T60_P2_F4_SL20","4ulysses16_T60_P2_F4_SL30","4ulysses16_T60_P2_F4_SL40","4ulysses16_T60_P2_F4_SL50","4ulysses16_T60_P2_F4_SL60","4ulysses16_T60_P2_F4_SL70","4ulysses16_T60_P2_F4_SL80"
		  								   ,"4ulysses16_T80_P2_F4_SL10","4ulysses16_T80_P2_F4_SL20","4ulysses16_T80_P2_F4_SL30","4ulysses16_T80_P2_F4_SL40","4ulysses16_T80_P2_F4_SL50","4ulysses16_T80_P2_F4_SL60","4ulysses16_T80_P2_F4_SL70","4ulysses16_T80_P2_F4_SL80"
		  								   ,"4ulysses16_T100_P2_F4_SL10","4ulysses16_T100_P2_F4_SL20","4ulysses16_T100_P2_F4_SL30","4ulysses16_T100_P2_F4_SL40","4ulysses16_T100_P2_F4_SL50","4ulysses16_T100_P2_F4_SL60","4ulysses16_T100_P2_F4_SL70","4ulysses16_T100_P2_F4_SL80"
		  								  
		  								   ,"5gr21_T40_P2_F4_SL10","5gr21_T40_P2_F4_SL20","5gr21_T40_P2_F4_SL30","5gr21_T40_P2_F4_SL40","5gr21_T40_P2_F4_SL50","5gr21_T40_P2_F4_SL60","5gr21_T40_P2_F4_SL70","5gr21_T40_P2_F4_SL80"
		  								   ,"5gr21_T60_P2_F4_SL10","5gr21_T60_P2_F4_SL20","5gr21_T60_P2_F4_SL30","5gr21_T60_P2_F4_SL40","5gr21_T60_P2_F4_SL50","5gr21_T60_P2_F4_SL60","5gr21_T60_P2_F4_SL70","5gr21_T60_P2_F4_SL80"
		  								   ,"5gr21_T80_P2_F4_SL10","5gr21_T80_P2_F4_SL20","5gr21_T80_P2_F4_SL30","5gr21_T80_P2_F4_SL40","5gr21_T80_P2_F4_SL50","5gr21_T80_P2_F4_SL60","5gr21_T80_P2_F4_SL70","5gr21_T80_P2_F4_SL80"
		  								   ,"5gr21_T100_P2_F4_SL10","5gr21_T100_P2_F4_SL20","5gr21_T100_P2_F4_SL30","5gr21_T100_P2_F4_SL40","5gr21_T100_P2_F4_SL50","5gr21_T100_P2_F4_SL60","5gr21_T100_P2_F4_SL70","5gr21_T100_P2_F4_SL80"
		  								  
          								   ,"5gr24_T40_P2_F4_SL10","5gr24_T40_P2_F4_SL20","5gr24_T40_P2_F4_SL30","5gr24_T40_P2_F4_SL40","5gr24_T40_P2_F4_SL50","5gr24_T40_P2_F4_SL60","5gr24_T40_P2_F4_SL70","5gr24_T40_P2_F4_SL80"
		  								   ,"5gr24_T60_P2_F4_SL10","5gr24_T60_P2_F4_SL20","5gr24_T60_P2_F4_SL30","5gr24_T60_P2_F4_SL40","5gr24_T60_P2_F4_SL50","5gr24_T60_P2_F4_SL60","5gr24_T60_P2_F4_SL70","5gr24_T60_P2_F4_SL80"
		  								   ,"5gr24_T80_P2_F4_SL10","5gr24_T80_P2_F4_SL20","5gr24_T80_P2_F4_SL30","5gr24_T80_P2_F4_SL40","5gr24_T80_P2_F4_SL50","5gr24_T80_P2_F4_SL60","5gr24_T80_P2_F4_SL70","5gr24_T80_P2_F4_SL80"
		  								   ,"5gr24_T100_P2_F4_SL10","5gr24_T100_P2_F4_SL20","5gr24_T100_P2_F4_SL30","5gr24_T100_P2_F4_SL40","5gr24_T100_P2_F4_SL50","5gr24_T100_P2_F4_SL60","5gr24_T100_P2_F4_SL70","5gr24_T100_P2_F4_SL80"
		  								  
          								   ,"5ulysses22_T40_P2_F4_SL10","5ulysses22_T40_P2_F4_SL20","5ulysses22_T40_P2_F4_SL30","5ulysses22_T40_P2_F4_SL40","5ulysses22_T40_P2_F4_SL50","5ulysses22_T40_P2_F4_SL60","5ulysses22_T40_P2_F4_SL70","5ulysses22_T40_P2_F4_SL80"
		  								   ,"5ulysses22_T60_P2_F4_SL10","5ulysses22_T60_P2_F4_SL20","5ulysses22_T60_P2_F4_SL30","5ulysses22_T60_P2_F4_SL40","5ulysses22_T60_P2_F4_SL50","5ulysses22_T60_P2_F4_SL60","5ulysses22_T60_P2_F4_SL70","5ulysses22_T60_P2_F4_SL80"
		  								   ,"5ulysses22_T80_P2_F4_SL10","5ulysses22_T80_P2_F4_SL20","5ulysses22_T80_P2_F4_SL30","5ulysses22_T80_P2_F4_SL40","5ulysses22_T80_P2_F4_SL50","5ulysses22_T80_P2_F4_SL60","5ulysses22_T80_P2_F4_SL70","5ulysses22_T80_P2_F4_SL80"
		  								   ,"5ulysses22_T100_P2_F4_SL10","5ulysses22_T100_P2_F4_SL20","5ulysses22_T100_P2_F4_SL30","5ulysses22_T100_P2_F4_SL40","5ulysses22_T100_P2_F4_SL50","5ulysses22_T100_P2_F4_SL60","5ulysses22_T100_P2_F4_SL70","5ulysses22_T100_P2_F4_SL80"
		  								  
          								   ,"6bayg29_T40_P2_F4_SL10","6bayg29_T40_P2_F4_SL20","6bayg29_T40_P2_F4_SL30","6bayg29_T40_P2_F4_SL40","6bayg29_T40_P2_F4_SL50","6bayg29_T40_P2_F4_SL60","6bayg29_T40_P2_F4_SL70","6bayg29_T40_P2_F4_SL80"
		  								   ,"6bayg29_T60_P2_F4_SL10","6bayg29_T60_P2_F4_SL20","6bayg29_T60_P2_F4_SL30","6bayg29_T60_P2_F4_SL40","6bayg29_T60_P2_F4_SL50","6bayg29_T60_P2_F4_SL60","6bayg29_T60_P2_F4_SL70","6bayg29_T60_P2_F4_SL80"
		  								   ,"6bayg29_T80_P2_F4_SL10","6bayg29_T80_P2_F4_SL20","6bayg29_T80_P2_F4_SL30","6bayg29_T80_P2_F4_SL40","6bayg29_T80_P2_F4_SL50","6bayg29_T80_P2_F4_SL60","6bayg29_T80_P2_F4_SL70","6bayg29_T80_P2_F4_SL80"
		  								   ,"6bayg29_T100_P2_F4_SL10","6bayg29_T100_P2_F4_SL20","6bayg29_T100_P2_F4_SL30","6bayg29_T100_P2_F4_SL40","6bayg29_T100_P2_F4_SL50","6bayg29_T100_P2_F4_SL60","6bayg29_T100_P2_F4_SL70","6bayg29_T100_P2_F4_SL80"
		  								  
          								   ,"6bays29_T40_P2_F4_SL10","6bays29_T40_P2_F4_SL20","6bays29_T40_P2_F4_SL30","6bays29_T40_P2_F4_SL40","6bays29_T40_P2_F4_SL50","6bays29_T40_P2_F4_SL60","6bays29_T40_P2_F4_SL70","6bays29_T40_P2_F4_SL80"
		  								   ,"6bays29_T60_P2_F4_SL10","6bays29_T60_P2_F4_SL20","6bays29_T60_P2_F4_SL30","6bays29_T60_P2_F4_SL40","6bays29_T60_P2_F4_SL50","6bays29_T60_P2_F4_SL60","6bays29_T60_P2_F4_SL70","6bays29_T60_P2_F4_SL80"
		  								   ,"6bays29_T80_P2_F4_SL10","6bays29_T80_P2_F4_SL20","6bays29_T80_P2_F4_SL30","6bays29_T80_P2_F4_SL40","6bays29_T80_P2_F4_SL50","6bays29_T80_P2_F4_SL60","6bays29_T80_P2_F4_SL70","6bays29_T80_P2_F4_SL80"
		  								   ,"6bays29_T100_P2_F4_SL10","6bays29_T100_P2_F4_SL20","6bays29_T100_P2_F4_SL30","6bays29_T100_P2_F4_SL40","6bays29_T100_P2_F4_SL50","6bays29_T100_P2_F4_SL60","6bays29_T100_P2_F4_SL70","6bays29_T100_P2_F4_SL80"
		  								  
          								   ,"6fri26_T40_P2_F4_SL10","6fri26_T40_P2_F4_SL20","6fri26_T40_P2_F4_SL30","6fri26_T40_P2_F4_SL40","6fri26_T40_P2_F4_SL50","6fri26_T40_P2_F4_SL60","6fri26_T40_P2_F4_SL70","6fri26_T40_P2_F4_SL80"
		  								   ,"6fri26_T60_P2_F4_SL10","6fri26_T60_P2_F4_SL20","6fri26_T60_P2_F4_SL30","6fri26_T60_P2_F4_SL40","6fri26_T60_P2_F4_SL50","6fri26_T60_P2_F4_SL60","6fri26_T60_P2_F4_SL70","6fri26_T60_P2_F4_SL80"
		  								   ,"6fri26_T80_P2_F4_SL10","6fri26_T80_P2_F4_SL20","6fri26_T80_P2_F4_SL30","6fri26_T80_P2_F4_SL40","6fri26_T80_P2_F4_SL50","6fri26_T80_P2_F4_SL60","6fri26_T80_P2_F4_SL70","6fri26_T80_P2_F4_SL80"
		  								   ,"6fri26_T100_P2_F4_SL10","6fri26_T100_P2_F4_SL20","6fri26_T100_P2_F4_SL30","6fri26_T100_P2_F4_SL40","6fri26_T100_P2_F4_SL50","6fri26_T100_P2_F4_SL60","6fri26_T100_P2_F4_SL70","6fri26_T100_P2_F4_SL80"
		  								  
          								   ,"7ftv33_T40_P2_F4_SL10","7ftv33_T40_P2_F4_SL20","7ftv33_T40_P2_F4_SL30","7ftv33_T40_P2_F4_SL40","7ftv33_T40_P2_F4_SL50","7ftv33_T40_P2_F4_SL60","7ftv33_T40_P2_F4_SL70","7ftv33_T40_P2_F4_SL80"
		  								   ,"7ftv33_T60_P2_F4_SL10","7ftv33_T60_P2_F4_SL20","7ftv33_T60_P2_F4_SL30","7ftv33_T60_P2_F4_SL40","7ftv33_T60_P2_F4_SL50","7ftv33_T60_P2_F4_SL60","7ftv33_T60_P2_F4_SL70","7ftv33_T60_P2_F4_SL80"
		  								   ,"7ftv33_T80_P2_F4_SL10","7ftv33_T80_P2_F4_SL20","7ftv33_T80_P2_F4_SL30","7ftv33_T80_P2_F4_SL40","7ftv33_T80_P2_F4_SL50","7ftv33_T80_P2_F4_SL60","7ftv33_T80_P2_F4_SL70","7ftv33_T80_P2_F4_SL80"
		  								   ,"7ftv33_T100_P2_F4_SL10","7ftv33_T100_P2_F4_SL20","7ftv33_T100_P2_F4_SL30","7ftv33_T100_P2_F4_SL40","7ftv33_T100_P2_F4_SL50","7ftv33_T100_P2_F4_SL60","7ftv33_T100_P2_F4_SL70","7ftv33_T100_P2_F4_SL80"
          
          								   ,"3burma14_T40_P2_F5_SL10","3burma14_T40_P2_F5_SL20","3burma14_T40_P2_F5_SL30","3burma14_T40_P2_F5_SL40","3burma14_T40_P2_F5_SL50","3burma14_T40_P2_F5_SL60","3burma14_T40_P2_F5_SL70","3burma14_T40_P2_F5_SL80"
		  								   ,"3burma14_T60_P2_F5_SL10","3burma14_T60_P2_F5_SL20","3burma14_T60_P2_F5_SL30","3burma14_T60_P2_F5_SL40","3burma14_T60_P2_F5_SL50","3burma14_T60_P2_F5_SL60","3burma14_T60_P2_F5_SL70","3burma14_T60_P2_F5_SL80"
		  								   ,"3burma14_T80_P2_F5_SL10","3burma14_T80_P2_F5_SL20","3burma14_T80_P2_F5_SL30","3burma14_T80_P2_F5_SL40","3burma14_T80_P2_F5_SL50","3burma14_T80_P2_F5_SL60","3burma14_T80_P2_F5_SL70","3burma14_T80_P2_F5_SL80"
		  								   ,"3burma14_T100_P2_F5_SL10","3burma14_T100_P2_F5_SL20","3burma14_T100_P2_F5_SL30","3burma14_T100_P2_F5_SL40","3burma14_T100_P2_F5_SL50","3burma14_T100_P2_F5_SL60","3burma14_T100_P2_F5_SL70","3burma14_T100_P2_F5_SL80"
		  								  
		  								   ,"4gr17_T40_P2_F5_SL10","4gr17_T40_P2_F5_SL20","4gr17_T40_P2_F5_SL30","4gr17_T40_P2_F5_SL40","4gr17_T40_P2_F5_SL50","4gr17_T40_P2_F5_SL60","4gr17_T40_P2_F5_SL70","4gr17_T40_P2_F5_SL80"
		  								   ,"4gr17_T60_P2_F5_SL10","4gr17_T60_P2_F5_SL20","4gr17_T60_P2_F5_SL30","4gr17_T60_P2_F5_SL40","4gr17_T60_P2_F5_SL50","4gr17_T60_P2_F5_SL60","4gr17_T60_P2_F5_SL70","4gr17_T60_P2_F5_SL80"
		  								   ,"4gr17_T80_P2_F5_SL10","4gr17_T80_P2_F5_SL20","4gr17_T80_P2_F5_SL30","4gr17_T80_P2_F5_SL40","4gr17_T80_P2_F5_SL50","4gr17_T80_P2_F5_SL60","4gr17_T80_P2_F5_SL70","4gr17_T80_P2_F5_SL80"
		  								   ,"4gr17_T100_P2_F5_SL10","4gr17_T100_P2_F5_SL20","4gr17_T100_P2_F5_SL30","4gr17_T100_P2_F5_SL40","4gr17_T100_P2_F5_SL50","4gr17_T100_P2_F5_SL60","4gr17_T100_P2_F5_SL70","4gr17_T100_P2_F5_SL80"
		  								  
		  								   ,"4ulysses16_T40_P2_F5_SL10","4ulysses16_T40_P2_F5_SL20","4ulysses16_T40_P2_F5_SL30","4ulysses16_T40_P2_F5_SL40","4ulysses16_T40_P2_F5_SL50","4ulysses16_T40_P2_F5_SL60","4ulysses16_T40_P2_F5_SL70","4ulysses16_T40_P2_F5_SL80"
		  								   ,"4ulysses16_T60_P2_F5_SL10","4ulysses16_T60_P2_F5_SL20","4ulysses16_T60_P2_F5_SL30","4ulysses16_T60_P2_F5_SL40","4ulysses16_T60_P2_F5_SL50","4ulysses16_T60_P2_F5_SL60","4ulysses16_T60_P2_F5_SL70","4ulysses16_T60_P2_F5_SL80"
		  								   ,"4ulysses16_T80_P2_F5_SL10","4ulysses16_T80_P2_F5_SL20","4ulysses16_T80_P2_F5_SL30","4ulysses16_T80_P2_F5_SL40","4ulysses16_T80_P2_F5_SL50","4ulysses16_T80_P2_F5_SL60","4ulysses16_T80_P2_F5_SL70","4ulysses16_T80_P2_F5_SL80"
		  								   ,"4ulysses16_T100_P2_F5_SL10","4ulysses16_T100_P2_F5_SL20","4ulysses16_T100_P2_F5_SL30","4ulysses16_T100_P2_F5_SL40","4ulysses16_T100_P2_F5_SL50","4ulysses16_T100_P2_F5_SL60","4ulysses16_T100_P2_F5_SL70","4ulysses16_T100_P2_F5_SL80"
		  								  
		  								   ,"5gr21_T40_P2_F5_SL10","5gr21_T40_P2_F5_SL20","5gr21_T40_P2_F5_SL30","5gr21_T40_P2_F5_SL40","5gr21_T40_P2_F5_SL50","5gr21_T40_P2_F5_SL60","5gr21_T40_P2_F5_SL70","5gr21_T40_P2_F5_SL80"
		  								   ,"5gr21_T60_P2_F5_SL10","5gr21_T60_P2_F5_SL20","5gr21_T60_P2_F5_SL30","5gr21_T60_P2_F5_SL40","5gr21_T60_P2_F5_SL50","5gr21_T60_P2_F5_SL60","5gr21_T60_P2_F5_SL70","5gr21_T60_P2_F5_SL80"
		  								   ,"5gr21_T80_P2_F5_SL10","5gr21_T80_P2_F5_SL20","5gr21_T80_P2_F5_SL30","5gr21_T80_P2_F5_SL40","5gr21_T80_P2_F5_SL50","5gr21_T80_P2_F5_SL60","5gr21_T80_P2_F5_SL70","5gr21_T80_P2_F5_SL80"
		  								   ,"5gr21_T100_P2_F5_SL10","5gr21_T100_P2_F5_SL20","5gr21_T100_P2_F5_SL30","5gr21_T100_P2_F5_SL40","5gr21_T100_P2_F5_SL50","5gr21_T100_P2_F5_SL60","5gr21_T100_P2_F5_SL70","5gr21_T100_P2_F5_SL80"
		  								  
          								   ,"5gr24_T40_P2_F5_SL10","5gr24_T40_P2_F5_SL20","5gr24_T40_P2_F5_SL30","5gr24_T40_P2_F5_SL40","5gr24_T40_P2_F5_SL50","5gr24_T40_P2_F5_SL60","5gr24_T40_P2_F5_SL70","5gr24_T40_P2_F5_SL80"
		  								   ,"5gr24_T60_P2_F5_SL10","5gr24_T60_P2_F5_SL20","5gr24_T60_P2_F5_SL30","5gr24_T60_P2_F5_SL40","5gr24_T60_P2_F5_SL50","5gr24_T60_P2_F5_SL60","5gr24_T60_P2_F5_SL70","5gr24_T60_P2_F5_SL80"
		  								   ,"5gr24_T80_P2_F5_SL10","5gr24_T80_P2_F5_SL20","5gr24_T80_P2_F5_SL30","5gr24_T80_P2_F5_SL40","5gr24_T80_P2_F5_SL50","5gr24_T80_P2_F5_SL60","5gr24_T80_P2_F5_SL70","5gr24_T80_P2_F5_SL80"
		  								   ,"5gr24_T100_P2_F5_SL10","5gr24_T100_P2_F5_SL20","5gr24_T100_P2_F5_SL30","5gr24_T100_P2_F5_SL40","5gr24_T100_P2_F5_SL50","5gr24_T100_P2_F5_SL60","5gr24_T100_P2_F5_SL70","5gr24_T100_P2_F5_SL80"
		  								  
          								   ,"5ulysses22_T40_P2_F5_SL10","5ulysses22_T40_P2_F5_SL20","5ulysses22_T40_P2_F5_SL30","5ulysses22_T40_P2_F5_SL40","5ulysses22_T40_P2_F5_SL50","5ulysses22_T40_P2_F5_SL60","5ulysses22_T40_P2_F5_SL70","5ulysses22_T40_P2_F5_SL80"
		  								   ,"5ulysses22_T60_P2_F5_SL10","5ulysses22_T60_P2_F5_SL20","5ulysses22_T60_P2_F5_SL30","5ulysses22_T60_P2_F5_SL40","5ulysses22_T60_P2_F5_SL50","5ulysses22_T60_P2_F5_SL60","5ulysses22_T60_P2_F5_SL70","5ulysses22_T60_P2_F5_SL80"
		  								   ,"5ulysses22_T80_P2_F5_SL10","5ulysses22_T80_P2_F5_SL20","5ulysses22_T80_P2_F5_SL30","5ulysses22_T80_P2_F5_SL40","5ulysses22_T80_P2_F5_SL50","5ulysses22_T80_P2_F5_SL60","5ulysses22_T80_P2_F5_SL70","5ulysses22_T80_P2_F5_SL80"
		  								   ,"5ulysses22_T100_P2_F5_SL10","5ulysses22_T100_P2_F5_SL20","5ulysses22_T100_P2_F5_SL30","5ulysses22_T100_P2_F5_SL40","5ulysses22_T100_P2_F5_SL50","5ulysses22_T100_P2_F5_SL60","5ulysses22_T100_P2_F5_SL70","5ulysses22_T100_P2_F5_SL80"
		  								  
          								   ,"6bayg29_T40_P2_F5_SL10","6bayg29_T40_P2_F5_SL20","6bayg29_T40_P2_F5_SL30","6bayg29_T40_P2_F5_SL40","6bayg29_T40_P2_F5_SL50","6bayg29_T40_P2_F5_SL60","6bayg29_T40_P2_F5_SL70","6bayg29_T40_P2_F5_SL80"
		  								   ,"6bayg29_T60_P2_F5_SL10","6bayg29_T60_P2_F5_SL20","6bayg29_T60_P2_F5_SL30","6bayg29_T60_P2_F5_SL40","6bayg29_T60_P2_F5_SL50","6bayg29_T60_P2_F5_SL60","6bayg29_T60_P2_F5_SL70","6bayg29_T60_P2_F5_SL80"
		  								   ,"6bayg29_T80_P2_F5_SL10","6bayg29_T80_P2_F5_SL20","6bayg29_T80_P2_F5_SL30","6bayg29_T80_P2_F5_SL40","6bayg29_T80_P2_F5_SL50","6bayg29_T80_P2_F5_SL60","6bayg29_T80_P2_F5_SL70","6bayg29_T80_P2_F5_SL80"
		  								   ,"6bayg29_T100_P2_F5_SL10","6bayg29_T100_P2_F5_SL20","6bayg29_T100_P2_F5_SL30","6bayg29_T100_P2_F5_SL40","6bayg29_T100_P2_F5_SL50","6bayg29_T100_P2_F5_SL60","6bayg29_T100_P2_F5_SL70","6bayg29_T100_P2_F5_SL80"
		  								  
          								   ,"6bays29_T40_P2_F5_SL10","6bays29_T40_P2_F5_SL20","6bays29_T40_P2_F5_SL30","6bays29_T40_P2_F5_SL40","6bays29_T40_P2_F5_SL50","6bays29_T40_P2_F5_SL60","6bays29_T40_P2_F5_SL70","6bays29_T40_P2_F5_SL80"
		  								   ,"6bays29_T60_P2_F5_SL10","6bays29_T60_P2_F5_SL20","6bays29_T60_P2_F5_SL30","6bays29_T60_P2_F5_SL40","6bays29_T60_P2_F5_SL50","6bays29_T60_P2_F5_SL60","6bays29_T60_P2_F5_SL70","6bays29_T60_P2_F5_SL80"
		  								   ,"6bays29_T80_P2_F5_SL10","6bays29_T80_P2_F5_SL20","6bays29_T80_P2_F5_SL30","6bays29_T80_P2_F5_SL40","6bays29_T80_P2_F5_SL50","6bays29_T80_P2_F5_SL60","6bays29_T80_P2_F5_SL70","6bays29_T80_P2_F5_SL80"
		  								   ,"6bays29_T100_P2_F5_SL10","6bays29_T100_P2_F5_SL20","6bays29_T100_P2_F5_SL30","6bays29_T100_P2_F5_SL40","6bays29_T100_P2_F5_SL50","6bays29_T100_P2_F5_SL60","6bays29_T100_P2_F5_SL70","6bays29_T100_P2_F5_SL80"
		  								  
          								   ,"6fri26_T40_P2_F5_SL10","6fri26_T40_P2_F5_SL20","6fri26_T40_P2_F5_SL30","6fri26_T40_P2_F5_SL40","6fri26_T40_P2_F5_SL50","6fri26_T40_P2_F5_SL60","6fri26_T40_P2_F5_SL70","6fri26_T40_P2_F5_SL80"
		  								   ,"6fri26_T60_P2_F5_SL10","6fri26_T60_P2_F5_SL20","6fri26_T60_P2_F5_SL30","6fri26_T60_P2_F5_SL40","6fri26_T60_P2_F5_SL50","6fri26_T60_P2_F5_SL60","6fri26_T60_P2_F5_SL70","6fri26_T60_P2_F5_SL80"
		  								   ,"6fri26_T80_P2_F5_SL10","6fri26_T80_P2_F5_SL20","6fri26_T80_P2_F5_SL30","6fri26_T80_P2_F5_SL40","6fri26_T80_P2_F5_SL50","6fri26_T80_P2_F5_SL60","6fri26_T80_P2_F5_SL70","6fri26_T80_P2_F5_SL80"
		  								   ,"6fri26_T100_P2_F5_SL10","6fri26_T100_P2_F5_SL20","6fri26_T100_P2_F5_SL30","6fri26_T100_P2_F5_SL40","6fri26_T100_P2_F5_SL50","6fri26_T100_P2_F5_SL60","6fri26_T100_P2_F5_SL70","6fri26_T100_P2_F5_SL80"
		  								  
          								   ,"7ftv33_T40_P2_F5_SL10","7ftv33_T40_P2_F5_SL20","7ftv33_T40_P2_F5_SL30","7ftv33_T40_P2_F5_SL40","7ftv33_T40_P2_F5_SL50","7ftv33_T40_P2_F5_SL60","7ftv33_T40_P2_F5_SL70","7ftv33_T40_P2_F5_SL80"
		  								   ,"7ftv33_T60_P2_F5_SL10","7ftv33_T60_P2_F5_SL20","7ftv33_T60_P2_F5_SL30","7ftv33_T60_P2_F5_SL40","7ftv33_T60_P2_F5_SL50","7ftv33_T60_P2_F5_SL60","7ftv33_T60_P2_F5_SL70","7ftv33_T60_P2_F5_SL80"
		  								   ,"7ftv33_T80_P2_F5_SL10","7ftv33_T80_P2_F5_SL20","7ftv33_T80_P2_F5_SL30","7ftv33_T80_P2_F5_SL40","7ftv33_T80_P2_F5_SL50","7ftv33_T80_P2_F5_SL60","7ftv33_T80_P2_F5_SL70","7ftv33_T80_P2_F5_SL80"
		  								   ,"7ftv33_T100_P2_F5_SL10","7ftv33_T100_P2_F5_SL20","7ftv33_T100_P2_F5_SL30","7ftv33_T100_P2_F5_SL40","7ftv33_T100_P2_F5_SL50","7ftv33_T100_P2_F5_SL60","7ftv33_T100_P2_F5_SL70","7ftv33_T100_P2_F5_SL80"};
          
          char Name_1[200];
          char Name_2[200];
          char Name_3[200];
          char Name_4[200];
          
          char ModelName[] = "Model_SCTTDPTW_ONLY_TW_AB_FS_";
          
          Write_Command = fopen("oku.txt","w");
          if(Write_Command == NULL)
          {
                    printf("The File (oku.txt) cannot be created!");
                    system("pause");
                    exit(1);
          }
          
          Read_MaxSolution = fopen("MAX.txt","r");
          if(Read_MaxSolution == NULL)
          {
                    printf("The File (MAX.txt) cannot be opened!");
                    system("pause");
                    exit(1);
          }
          
          Read_MinSolution = fopen("MIN.txt","r");
          if(Read_MinSolution == NULL)
          {
                    printf("The File (MIN.txt) cannot be opened!");
                    system("pause");
                    exit(1);
          }
          
          fprintf(Write_Command,"set\n");
          fprintf(Write_Command,"workmem\n");
          fprintf(Write_Command,"1024\n\n");
          
          fprintf(Write_Command,"set\n");
          fprintf(Write_Command,"timelimit\n");
          fprintf(Write_Command,"21600\n\n");
          
          fprintf(Write_Command,"set\n");
          fprintf(Write_Command,"mip\n");
          fprintf(Write_Command,"strategy\n");
          fprintf(Write_Command,"file\n");
          fprintf(Write_Command,"3\n\n");
          
          //--------------------------------------------------------------
		  for(Problem_Index = 1 ; Problem_Index <= 1600 ; Problem_Index++)
          {
                    strcpy(Name_1,"");
                    strcpy(Name_1,ProblemName[Problem_Index]);
                    strcat(Name_1,".txt");
          
                    Reset_AllMatrices();
                    Read_Information(Name_1,Problem_Index);
          
                    strcpy(Name_2,"");
                    strcpy(Name_2,ModelName);
                    strcat(Name_2,ProblemName[Problem_Index]);
                    strcat(Name_2,".lp");
                              
                    strcpy(Name_3,"");
                    strcpy(Name_3,"C:\\");
                    strcat(Name_3,ModelName);
                    strcat(Name_3,ProblemName[Problem_Index]);
                    strcat(Name_3,"_Sonuc.log");
                              
                    strcpy(Name_4,"");
                    strcpy(Name_4,"C:\\");
                    strcat(Name_4,ModelName);
                    strcat(Name_4,ProblemName[Problem_Index]);
                    strcat(Name_4,".lp");
                              
                    fprintf(Write_Command,"set logfile %s\n",Name_3);
                    fprintf(Write_Command,"read %s\n",Name_4);
                    fprintf(Write_Command,"mipopt\n");
                    fprintf(Write_Command,"dis sol var *\n\n");
                              
                    Write_Model = fopen(Name_2,"w");
                    if(Write_Model == NULL)
                    {
                              printf("%s Dosyasi Yaratilamiyor!\n",Name_2);
                              system("pause");
                              exit(1);
                    }
                              
                    Objective_Function();
                    Fuzzy_Constraint();
                    First_Constraint();
                    Second_Constraint();
                    Third_Constraint();
                    Fourth_Constraint();
                    Fifth_Constraint();
                    Sixth_Constraint();
                    //Seventh_Constraint();
                    //Eighth_Constraint();
                    //Ninth_Constraint();
                    Tenth_Constraint();
                    //Eleventh_Constraint(); // Açýlabilir. Her Salkýmdan uðranýlacak müþteri sayýsý sýnýrlarý veriyor.
                    Twelfth_Constraint();
                    //Time_Constraint();
                    Binaries();
                              
                    fclose(Write_Model);
                    
                    puts(Name_1);
          }
          
          fclose(Write_Command);
          fclose(Read_MaxSolution);
          fclose(Read_MinSolution);
          
          system("pause");
	      return 0;
}

// Farklý düðümlerin ayný salkýmda olup olmadýðýný kontrol eder.
//-------------------------------------------------------------
int Control(int Node_1,int Node_2)
{
	      int Cluster,Customer;
	      int Cluster_1,Cluster_2;
	      int TurnValue;
	      
	      //--------------------------------------------------------
		  for(Cluster = 1 ; Cluster <= NumberOfClusters ; Cluster++)
	      {
		            //------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)
		            {
			                  if(ClusterMatrix[Cluster][Customer] == -1)
				                        break;
				                        
                              if(ClusterMatrix[Cluster][Customer] == Node_1)
                                        Cluster_1 = Cluster;
                                        
                              if(ClusterMatrix[Cluster][Customer] == Node_2)
				                        Cluster_2 = Cluster;
                    }
          }
          
          //------------------------
          if(Cluster_1 == Cluster_2)
		            TurnValue = 0;
          else
		            TurnValue = 1;
          
          return TurnValue;
}

// Tüm matris deðerlerini sýfýrlar.
//----------------------------------------------------------------------------//
void Reset_AllMatrices(void)
{
          int Cluster,Customer_1,Customer_2;
          
          //---------------------------------------------------
		  for(Cluster = 0 ; Cluster < NumberOfSets ; Cluster++)
					for(Customer_1 = 0 ; Customer_1 < NumberOfVertices ; Customer_1++)
                              ClusterMatrix[Cluster][Customer_1] = -1;
                          
          //----------------------------------------------------------------
		  for(Customer_1 = 0 ; Customer_1 < NumberOfVertices ; Customer_1++)
                    for(Customer_2 = 0 ; Customer_2 < NumberOfVertices ; Customer_2++)
                          TimeMatrix[Customer_1][Customer_2] = 0;
          
          //---------------------------------------------------
		  for(Cluster = 0 ; Cluster < NumberOfSets ; Cluster++)
          {
                    NumberOfCustomer_InCluster[Cluster] = 0;
                    
                    LimitofCustomerNumber_InCluster[Cluster][0] = 0;
                    LimitofCustomerNumber_InCluster[Cluster][1] = 0;
		  }
                                   
          //----------------------------------------------------------------
		  for(Customer_1 = 0 ; Customer_1 < NumberOfVertices ; Customer_1++)
          {
                    Profit[Customer_1] = 0;
                    
          			TimeWindow[Customer_1][0] = 0;
          			TimeWindow[Customer_1][1] = 0;
		  }              
}

// Problem verilerini ilgili dosyalardan okur.
//------------------------------------------------------------------------------
void Read_Information(char isim[],int Index)
{
          int Cluster,Customer;
          int Customer_1,Customer_2;
          int CustomerNumber;
          char Karakter[500] = "";
          int Remainder;
          int Set;
          
          //-------------------------------------------------------
		  Information = fopen(isim,"r");
	      if(Information == NULL)
	      {
		            printf("The File (%s) cannot be opened!",isim);
		            system("pause");
		            exit(1);
          }
	      
	      //-------------------------------------------------------
          while( strcmp(Karakter,"DIMENSION:") != 0 )
	                fscanf(Information,"%s",Karakter);
       
	      fscanf(Information,"%d",&NumberOfCustomers);
	      
	      //-------------------------------------------------------
          while( strcmp(Karakter,"SET:") != 0 )
	                fscanf(Information,"%s",Karakter);
       
	      fscanf(Information,"%d",&NumberOfClusters);
	      
	      //-------------------------------------------------------
	      while( strcmp(Karakter,"TMAX:") != 0 )
	                fscanf(Information,"%s",Karakter);
	      
          fscanf(Information,"%ld",&TMax);
	      
	      //-------------------------------------------------------
	      while( strcmp(Karakter,"FUZZY_MIN:") != 0 )
	                fscanf(Information,"%s",Karakter);
	      
          fscanf(Information,"%ld",&FuzzyParameter_Min);
          
          if(Index % 320 == 1)
                    rewind(Read_MinSolution);
                    
          if(Index % 8 == 1)
          {
                    for(Set = 1 ; Set <= 8 ; Set++)
          			{
                              fscanf(Read_MinSolution,"%ld",&FuzzyParameter_Min);
                              
							  if(Set == 5)
                                        MinSolution = FuzzyParameter_Min;
		  		    }
		  }
					
		  FuzzyParameter_Min = MinSolution;
          
          //-------------------------------------------------------
	      while( strcmp(Karakter,"FUZZY_VU:") != 0 )
	                fscanf(Information,"%s",Karakter);
	      
          fscanf(Information,"%ld",&FuzzyParameter_Vu);
          
          //-------------------------------------------------------
	      while( strcmp(Karakter,"FUZZY_MAX:") != 0 )
	                fscanf(Information,"%s",Karakter);
	      
          fscanf(Information,"%ld",&FuzzyParameter_Max);
          
          if(Index % 320 == 1)
                    rewind(Read_MaxSolution);
                    
          if(Index % 8 == 1)
          {
                    for(Set = 1 ; Set <= 8 ; Set++)
          			{
                              fscanf(Read_MaxSolution,"%ld",&FuzzyParameter_Max);
                              
							  if(Set == 5)
                                        MaxSolution = FuzzyParameter_Max;
		  		    }
		  }
					
		  FuzzyParameter_Max = MaxSolution;
		
          /*
          if(Index % 8 == 1)
                    MaxSolution = FuzzyParameter_Max;
          else
                    FuzzyParameter_Max = MaxSolution;
          */
          
          if(Index >= 1 && Index <= 320)
		            FuzzyParameter_Vu = FuzzyParameter_Min + 0.00 * (FuzzyParameter_Max - FuzzyParameter_Min);
		  
		  if(Index >= 321 && Index <= 640)
		            FuzzyParameter_Vu = FuzzyParameter_Min + 0.25 * (FuzzyParameter_Max - FuzzyParameter_Min);
		  
		  if(Index >= 641 && Index <= 960)
		            FuzzyParameter_Vu = FuzzyParameter_Min + 0.50 * (FuzzyParameter_Max - FuzzyParameter_Min);
		  
		  if(Index >= 961 && Index <= 1280)
		            FuzzyParameter_Vu = FuzzyParameter_Min + 0.75 * (FuzzyParameter_Max - FuzzyParameter_Min);
		  
		  if(Index >= 1281 && Index <= 1600)
		            FuzzyParameter_Vu = FuzzyParameter_Min + 1.00 * (FuzzyParameter_Max - FuzzyParameter_Min);
		  
          //-------------------------------------------------------
	      while( strcmp(Karakter,"SECURITY_LEVEL:") != 0 )
	                fscanf(Information,"%s",Karakter);
	      
          fscanf(Information,"%lf",&SecurityLevel);
          
          Remainder = Index % 8;
							  	  
		  if(Remainder == 1)
		            SecurityLevel = -1 * SecurityLevel;
							  
		  if(Remainder == 2)
					SecurityLevel = -1 * SecurityLevel;
					          
		  if(Remainder == 3)
					SecurityLevel = -1 * SecurityLevel;
							  
		  if(Remainder == 4)
					SecurityLevel = -1 * SecurityLevel;
							  
		  if(Remainder == 5)
					SecurityLevel = 0;
					          
		  if(Remainder == 6)
					SecurityLevel = -1 * SecurityLevel;
		  
		  if(Remainder == 7)
					SecurityLevel = -1 * SecurityLevel;
					
		  if(Remainder == 0)
					SecurityLevel = -1 * SecurityLevel;
		  
          //-------------------------------------------------------
          Remainder = Index % 8;
							  
		  if(Remainder == 1)
		            Value_ln = log(0.1);
							  
		  if(Remainder == 2)
					Value_ln = log(0.2);
					          
		  if(Remainder == 3)
					Value_ln = log(0.3);
							  
		  if(Remainder == 4)
					Value_ln = log(0.4);
							  
		  if(Remainder == 5)
					Value_ln = log(0.5);
					          
		  if(Remainder == 6)
					Value_ln = log(0.6);
		  
		  if(Remainder == 7)
					Value_ln = log(0.7);
								          
		  if(Remainder == 0)
					Value_ln = log(0.8);
          
	      //-------------------------------------------------------
          while( strcmp(Karakter,"EDGE_WEIGHT_SECTION:") != 0 )
	                fscanf(Information,"%s",Karakter);
          
		  for(Customer_1 = 1 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
                    for(Customer_2 = 1 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
                          fscanf(Information,"%ld",&TimeMatrix[Customer_1][Customer_2]);
          
	      //-------------------------------------------------------
	      while( strcmp(Karakter,"Vertex_List:") != 0 )
	                fscanf(Information,"%s",Karakter);
	      
	      for(Cluster = 1 ; Cluster <= NumberOfClusters ; Cluster++)
	      {
                    fscanf(Information,"%d",&LimitofCustomerNumber_InCluster[Cluster][0]);
					fscanf(Information,"%d",&LimitofCustomerNumber_InCluster[Cluster][1]);
					fscanf(Information,"%d",&NumberOfCustomer_InCluster[Cluster]);
                    
                    for(Customer = 1 ; Customer <= NumberOfCustomer_InCluster[Cluster] ; Customer++)
                              fscanf(Information,"%d",&ClusterMatrix[Cluster][Customer]);
          }
          
          //-------------------------------------------------------
	      while( strcmp(Karakter,"Latest_Time") != 0 )
	                fscanf(Information,"%s",Karakter);
	      
	      for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)
	      {
                    fscanf(Information,"%d",&CustomerNumber);
					fscanf(Information,"%ld",&TimeWindow[Customer][0]);
					fscanf(Information,"%ld",&TimeWindow[Customer][1]);
          }
          
          //-------------------------------------------------------
	      while( strcmp(Karakter,"Customer_Prize:") != 0 )
	                fscanf(Information,"%s",Karakter);
             
          for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)
          {
                    fscanf(Information,"%d",&CustomerNumber);
                    fscanf(Information,"%ld",&Profit[Customer]);
          }
          
          //-------------------------------------------------------
	      fclose(Information);
}

// Amaç fonksiyonunu dosyaya yazar.
//------------------------------------------------------------------------------
void Objective_Function(void)
{
          int Cluster,Customer;
          int Client;
          int Counter;
          
          fprintf(Write_Model,"MAXIMIZE\n");
          
          fprintf(Write_Model,"ALFA - BETA");
          
          fprintf(Write_Model,"\n\nSUBJECT TO\n\n");
}

// Intuitionistic bulanýk yapýda kýsýtlarý dosyaya yazar.
//------------------------------------------------------------------------------
void Fuzzy_Constraint(void)
{
          int Cluster,Customer;
          int Client;
          int Counter;
          
          //------------------------------------------------------------
          fprintf(Write_Model,"TP"); 
          
		  for(Customer = 2 ; Customer <= NumberOfCustomers ; Customer++) 
		  {             
                    fprintf(Write_Model," -\n%ldY%d",Profit[Customer],Customer);   
                    
					if(Customer == NumberOfCustomers) 
					          break;                                       
          }
          
          fprintf(Write_Model," = 0\n\n");   
          
          //------------------------------------------------------------
          for(Customer = 2 ; Customer <= NumberOfCustomers ; Customer++) 
		  {             
                    fprintf(Write_Model,"%ldY%d",Profit[Customer],Customer);   
					
					if(Customer == NumberOfCustomers) 
					          break;
					
					else
					          fprintf(Write_Model," +\n");                                              
          }
          
          fprintf(Write_Model," -\n%ldALFA\n",FuzzyParameter_Max - FuzzyParameter_Min);
          
          fprintf(Write_Model,">= %ld\n\n",FuzzyParameter_Min);
	      
	      //------------------------------------------------------------
	      for(Customer = 2 ; Customer <= NumberOfCustomers ; Customer++) 
		  {             
                    fprintf(Write_Model,"%ldY%d",Profit[Customer],Customer);   
					
					if(Customer == NumberOfCustomers) 
					          break;
					
					else
					          fprintf(Write_Model," +\n");                                              
          }
          
          fprintf(Write_Model," +\n%ldBETA\n",FuzzyParameter_Vu - FuzzyParameter_Min);
          
          fprintf(Write_Model,">= %ld\n\n",FuzzyParameter_Vu);
	      
	      //------------------------------------------------------------------------------
	      
	      fprintf(Write_Model,"ALFA + BETA <= 1\n\n");
	      
	      //------------------------------------------------------------------------------
	      
	      fprintf(Write_Model,"ALFA - BETA >= 0\n\n");
}

// Depodan çýkýþý saðlayan kýsýt yazýlýr.
//------------------------------------------------------------------------------
void First_Constraint(void)
{
          int Customer;
          
	      //-----------------------------------------------------------
		  for(Customer = 2 ; Customer <= NumberOfCustomers ; Customer++)
	      {
                    fprintf(Write_Model,"X%d_%d",1,Customer);
                    
                    if(Customer == NumberOfCustomers)
                              fprintf(Write_Model," = 1\n");
                    
					else
                              fprintf(Write_Model," +\n");
          }
          
          fprintf(Write_Model,"\n");  
}

// Depoya geri dönüþü saðlayan kýsýt yazýlýr.
//------------------------------------------------------------------------------
void Second_Constraint(void)
{
          int Customer;
          
	      //------------------------------------------------------------
		  for(Customer = 2 ; Customer <= NumberOfCustomers ; Customer++)
	      {
                    fprintf(Write_Model,"X%d_%d",Customer,1);
                    
                    if(Customer == NumberOfCustomers)
                              fprintf(Write_Model," = 1\n");
                    
					else
                              fprintf(Write_Model," +\n");
          }
          
	      fprintf(Write_Model,"\n");    
}

// Her düðüm için çýkýþ kýsýtlarý yazýlýr.
//------------------------------------------------------------------------------
void Third_Constraint(void)
{
          int Customer_1,Customer_2;
          int Counter;
          
          //-----------------------------------------------------------------
          for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
	      {
                    Counter = 0;
                    
                    //------------------------------------------------------------------
					for(Customer_2 = 1 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
		            {
                              if(Customer_1 != Customer_2)
                              {
                                        Counter++;
                                        
                                        if(Counter == 1)
                                                  fprintf(Write_Model,"X%d_%d",Customer_1,Customer_2); 
                                        
										else
                                                  fprintf(Write_Model," +\nX%d_%d",Customer_1,Customer_2);  
                              }
                    }
                    
                    fprintf(Write_Model," -\nY%d = 0\n\n",Customer_1);   
          }
}

// Her düðüm için giriþ kýsýtlarý yazýlýr.
//------------------------------------------------------------------------------
void Fourth_Constraint(void)
{
          int Customer_1,Customer_2;
          int Counter;
          
          //------------------------------------------------------------------
		  for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
	      {
                    Counter = 0;
                    
                    //------------------------------------------------------------------
					for(Customer_2 = 1 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
		            {
                              if(Customer_1 != Customer_2)
                              {
                                        Counter++;
                                        
                                        if(Counter == 1)
                                                  fprintf(Write_Model,"X%d_%d",Customer_2,Customer_1); 
                                        
                                        else
                                                  fprintf(Write_Model," +\nX%d_%d",Customer_2,Customer_1);  
                              }
                    }
                    
                    fprintf(Write_Model," -\nY%d = 0\n\n",Customer_1);   
          }
}

// Her salkým için çýkýþ kýsýtlarý yazýlýr.
//------------------------------------------------------------------------------
void Fifth_Constraint(void)
{
          int Cluster,Customer;
          int Client;
          int Counter;
          
          //--------------------------------------------------------
		  for(Cluster = 2 ; Cluster <= NumberOfClusters ; Cluster++)
	      {
                    Counter = 0;
                    
                    //------------------------------------------------------------
                    for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)
		            {
			                  if(ClusterMatrix[Cluster][Customer] == -1)
				                        break;
                              
							  else
			                  {
                                        //------------------------------------------------------
										for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        {
					                              if(ClusterMatrix[Cluster][Customer] != Client)
					                              {
						                                    if(Control(ClusterMatrix[Cluster][Customer],Client) == 1)
						                                    {
							                                          Counter++;
							                                          
							                                          if(Counter == 1)
                                                                                fprintf(Write_Model,"X%d_%d",ClusterMatrix[Cluster][Customer],Client);
                                                                      
																	  else
                                                                                fprintf(Write_Model," +\nX%d_%d",ClusterMatrix[Cluster][Customer],Client);
                                                            }
		                                          }
	                                    }
                              }
                    }
                    
                    fprintf(Write_Model," <= 1\n\n");
	      }
}

// Her salkým için giriþ kýsýtlarý yazýlýr.
//------------------------------------------------------------------------------
void Sixth_Constraint(void)
{
          int Cluster,Customer;
          int Client;
          int Counter;
          
          //--------------------------------------------------------
		  for(Cluster = 2 ; Cluster <= NumberOfClusters ; Cluster++)
	      {
                    Counter = 0;
                    
                    //------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)
		            {
			                  if(ClusterMatrix[Cluster][Customer] == -1)
				                        break;
                              
							  else
			                  {
                                        //------------------------------------------------------
										for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        {
					                              if(ClusterMatrix[Cluster][Customer] != Client)
					                              {
						                                    if(Control(ClusterMatrix[Cluster][Customer],Client) == 1)
						                                    {
							                                          Counter++;
							                                          
							                                          if(Counter == 1)
                                                                                fprintf(Write_Model,"X%d_%d",Client,ClusterMatrix[Cluster][Customer]);
                                                                      
																	  else
                                                                                fprintf(Write_Model," +\nX%d_%d",Client,ClusterMatrix[Cluster][Customer]);
                                                            }
		                                          }
	                                    }
                              }
                    }
                    
                    fprintf(Write_Model," <= 1\n\n");
	      }
}

// Alt tur engelleme kýsýtlarý yazýlýr.
//------------------------------------------------------------------------------
void Seventh_Constraint(void)
{
          int Customer_1,Customer_2;
          
          //------------------------------------------------------------------
		  for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++) 
          {
                    //-----------------------------------------------------------------
					for(Customer_2 = 2 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
                    {
                              if(Customer_1 != Customer_2) 
                              {
                                        //if(Control(Customer_1,Customer_2) == 1)
                                                  fprintf(Write_Model,"U%d - U%d + %dX%d_%d + %dX%d_%d <= %d\n",Customer_1,Customer_2,NumberOfCustomers,Customer_1,Customer_2,NumberOfCustomers - 2,Customer_2,Customer_1,NumberOfCustomers - 1);
                              }
                    }
          }
          
          fprintf(Write_Model,"\n");
}

// Alt tur engellemede kullanýlan yardýmcý kýsýtlar yazýlýr.
//------------------------------------------------------------------------------
void Eighth_Constraint(void)
{
          int Customer_1,Customer_2;
          
          //------------------------------------------------------------------
		  for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++) 
          {
                    fprintf(Write_Model,"U%d",Customer_1); 
                    
                    fprintf(Write_Model," -\nX%d_%d",1,Customer_1); 
                    
                    //------------------------------------------------------------------
					for(Customer_2 = 2 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
                    {
                              if(Customer_1 != Customer_2)
                                         //if(Control(Customer_1,Customer_2) == 1)
                                                   fprintf(Write_Model," -\n%dX%d_%d",2,Customer_2,Customer_1); 
                    }
                    
                    fprintf(Write_Model," >= 0\n\n"); 
          }
          
          fprintf(Write_Model,"\n");
}

// Alt tur engellemede kullanýlan yardýmcý kýsýtlar yazýlýr.
//------------------------------------------------------------------------------
void Ninth_Constraint(void)
{         
          int Customer_1,Customer_2;
          
          //------------------------------------------------------------------
		  for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++) 
          { 
                    fprintf(Write_Model,"U%d",Customer_1); 
                    
                    fprintf(Write_Model," +\n%dX%d_%d",NumberOfCustomers - 3,1,Customer_1); 
                    
                    //------------------------------------------------------------------
					for(Customer_2 = 2 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
                    {
                              if(Customer_1 != Customer_2)
                                        //if(Control(Customer_1,Customer_2) == 1)
                                                 fprintf(Write_Model," -\n%dX%d_%d",NumberOfCustomers - 2,Customer_1,Customer_2); 
                          
                    }
                    
                    fprintf(Write_Model," -\n%dX%d_%d",NumberOfCustomers - 1,Customer_1,1);
                    
                    fprintf(Write_Model," <= 0\n\n");
          }
          
          fprintf(Write_Model,"\n");
}

// Salkýmlar arasý akýþ korunum kýsýtlarý yazýlýr.
//------------------------------------------------------------------------------
void Tenth_Constraint(void)
{
          int Cluster,Customer;
          int Client;
          int Counter;
          int NumberOfThings;
          
          //--------------------------------------------------------
		  for(Cluster = 2 ; Cluster <= NumberOfClusters ; Cluster++)
          {
                    NumberOfThings = 0;
                    
                    //------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)
                    {
                              if(ClusterMatrix[Cluster][Customer] == -1)
                                        break;
                              
							  else
                                        NumberOfThings++;
                    }
                    
                    //--------------------
					if(NumberOfThings >= 1)
                    {
                              Counter = 0;
                              
                              //------------------------------------------------------------
							  for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)  // s1 salkýmýný yönetiyor
                              {
                                        if(ClusterMatrix[Cluster][Customer] == -1)
                                                  break;
                                        
										else
                                        {
                                                  //------------------------------------------------------
												  for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
                                                  {
                                                            if(ClusterMatrix[Cluster][Customer] != Client)
                                                            {
                                                                      if(Control(ClusterMatrix[Cluster][Customer],Client) == 1)
			                                                          {
                                                                                Counter++;
                                                                                
                                                                                if(Counter == 1)
                                                                                          fprintf(Write_Model,"X%d_%d",Client,ClusterMatrix[Cluster][Customer]);
                                                                                
																				else
                                                                                          fprintf(Write_Model," +\nX%d_%d",Client,ClusterMatrix[Cluster][Customer]);
                                                                      }
                                                            }
                                                  }  
                                        }
                              }
                              
                              //------------------------------------------------------------
                              for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)  // s1 salkýmýný yönetiyor
                              {
                                        if(ClusterMatrix[Cluster][Customer] == -1)
                                                  break;
                                        
										else
                                        {
                                                  //------------------------------------------------------
												  for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
                                                  {
                                                            if(ClusterMatrix[Cluster][Customer] != Client)
                                                            {
                                                                      if(Control(ClusterMatrix[Cluster][Customer],Client) == 1)
			                                                          {
                                                                                fprintf(Write_Model," -\nX%d_%d",ClusterMatrix[Cluster][Customer],Client);
                                                                      }
                                                            }
                                                  }
                                        }
                              }
                              
                              fprintf(Write_Model," = 0\n\n");           
                    }
          }
}

// Her salkýmdan uðranýlacak müþteri sayýsýna sýnýr getiren kýsýtlar yazýlýr.
//------------------------------------------------------------------------------
void Eleventh_Constraint(void)
{
          int Cluster,Customer;
          
          //--------------------------------------------------------
		  for(Cluster = 2 ; Cluster <= NumberOfClusters ; Cluster++)
          {
                    //------------------------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomer_InCluster[Cluster] ; Customer++)
                    {
                    		  fprintf(Write_Model,"Y%d",ClusterMatrix[Cluster][Customer]);               
                    		  
                              if(Customer != NumberOfCustomer_InCluster[Cluster])
                                        fprintf(Write_Model," +\n");               
							  
							  if(Customer == NumberOfCustomer_InCluster[Cluster])
							            fprintf(Write_Model," >= %d\n\n",LimitofCustomerNumber_InCluster[Cluster][0]);  
					}
		  }
		  
		  //--------------------------------------------------------
		  for(Cluster = 2 ; Cluster <= NumberOfClusters ; Cluster++)
          {
                    //------------------------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomer_InCluster[Cluster] ; Customer++)
                    {
                    		  fprintf(Write_Model,"Y%d",ClusterMatrix[Cluster][Customer]);               
                    		  
                              if(Customer != NumberOfCustomer_InCluster[Cluster])
                                        fprintf(Write_Model," +\n");               
							  
							  if(Customer == NumberOfCustomer_InCluster[Cluster])
							            fprintf(Write_Model," <= %d\n\n",LimitofCustomerNumber_InCluster[Cluster][1]);  
					}
		  }      
}

// Zaman penceresi için þans kýsýtlarý yazýlýyor.
//------------------------------------------------------------------------------
void Twelfth_Constraint(void)
{
          int Cluster,Customer,Client;
          int Customer_1,Customer_2;
          int Counter = 0;
          
          // Depodan çýkýþlarda zaman ilerletmek amacýyla kullanýlýr.
          //------------------------------------------------------------
          
          for(Customer = 2 ; Customer <= NumberOfCustomers ; Customer++)    
                     fprintf(Write_Model,"T%d_%d - %lfX%d_%d >= 0\n",1,Customer,-1*Value_ln*(double)TimeMatrix[1][Customer],1,Customer);
          
          fprintf(Write_Model,"\n\n");  
          
          // Zamaný kümülatif olarak toplar.
          //--------------------------------------------------------
          for(Cluster = 2 ; Cluster <= NumberOfClusters ; Cluster++)
	      {
		            //------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++)
		            {
                              if(ClusterMatrix[Cluster][Customer] == -1)
				                        break;
                              else
			                  {
				                        Counter = 0;
				                        
                                        //------------------------------------------------------
										for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        {
                                                  if(ClusterMatrix[Cluster][Customer] != Client)
					                              {
						                                    Counter++;
						                                    
						                                    if(Counter == 1)
                                                                      fprintf(Write_Model,"T%d_%d",ClusterMatrix[Cluster][Customer],Client);
                                                            
															else
                                                                      fprintf(Write_Model," +\nT%d_%d",ClusterMatrix[Cluster][Customer],Client);
		                                          }
	                                    }
	                                    
                                        //------------------------------------------------------
                                        for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        {
                                                  if(ClusterMatrix[Cluster][Customer] != Client)
					                              {       
                                                            fprintf(Write_Model," -\nT%d_%d",Client,ClusterMatrix[Cluster][Customer]);
		                                          }
	                                    }
	                                    
	                                    //------------------------------------------------------
	                                    for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        {
                                                  if(ClusterMatrix[Cluster][Customer] != Client)
					                              {       
                                                            fprintf(Write_Model," -\n%dX%d_%d",TimeMatrix[ClusterMatrix[Cluster][Customer]][Client],ClusterMatrix[Cluster][Customer],Client);
		                                          }
	                                    }
	                                    
	                                    //------------------------------------------------------
	                                    if(SecurityLevel != 0.0)
	                                    {
	                                              for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        		  {
                                                            if(ClusterMatrix[Cluster][Customer] != Client)
					                              			{       
                                                                      if(SecurityLevel > 0.0)
																	            fprintf(Write_Model," -\n%lfX%d_%d",SecurityLevel*(double)TimeMatrix[ClusterMatrix[Cluster][Customer]][Client],ClusterMatrix[Cluster][Customer],Client);
																	  
																	  if(SecurityLevel < 0.0)
																	            fprintf(Write_Model," +\n%lfX%d_%d",-1*SecurityLevel*(double)TimeMatrix[ClusterMatrix[Cluster][Customer]][Client],ClusterMatrix[Cluster][Customer],Client);          
		                                          			}
	                                              }
										}
										
	                                    fprintf(Write_Model," >= 0\n\n"); 
                              }
                    }
          }
          
		  // Depoya geri dönüþ zamaný dikkate alýr ve Tmax sýnýrý aþýlmamasýný saðlar.
		  //------------------------------------------------------------
          for(Customer_1 = 1 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
	      {
		            for(Customer_2 = 1 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
		            {
			                  if(Customer_1 != Customer_2)
			                  {
                                        fprintf(Write_Model,"T%d_%d - %dX%d_%d <= 0\n",Customer_1,Customer_2,TMax,Customer_1,Customer_2);
                              }
                     }
          }
          
          fprintf(Write_Model,"\n"); 
		  
          //Zaman Pencereleri (En Erken) kýsýtlarý yazýlýr.
          //------------------------------------------------------------
		  for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
	      {
		            Counter = 0;
		            
					for(Customer_2 = 1 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
		            {
							  if(Customer_1 != Customer_2)
			                  {
                                        Counter++;
                                        
										if(Counter == 1)
                                                  fprintf(Write_Model,"T%d_%d",Customer_2,Customer_1);
                                        
										else
                                                  fprintf(Write_Model," +\nT%d_%d",Customer_2,Customer_1);
                              }
                     }
                     
                     fprintf(Write_Model," -\n%ldY%d >= 0\n\n",TimeWindow[Customer_1][0],Customer_1);
          }
		  
		  //Zaman Pencereleri (En Geç) kýsýtlarý yazýlýr.
		  //------------------------------------------------------------
		  for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
	      {
		            Counter = 0;
		            
					for(Customer_2 = 1 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
		            {
							  if(Customer_1 != Customer_2)
			                  {
                                        Counter++;
                                        
										if(Counter == 1)
                                                  fprintf(Write_Model,"T%d_%d",Customer_2,Customer_1);
                                        
										else
                                                  fprintf(Write_Model," +\nT%d_%d",Customer_2,Customer_1);
                              }
                     }
                     
                     fprintf(Write_Model," -\n%ldY%d <= 0\n\n",TimeWindow[Customer_1][1],Customer_1);
          }
}

// Toplam seyahat süre sýnýrý için þans kýsýtlarý yazýlýr.
//------------------------------------------------------------------------------
void Time_Constraint(void)
{
          int Cluster,Customer;
          int Client;
          int Counter;
          
          Counter = 0;
          
          //--------------------------------------------------------
		  for(Cluster = 1 ; Cluster <= NumberOfClusters ; Cluster++)
	      {
                    //------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++) 
		            {
                              if(ClusterMatrix[Cluster][Customer] == -1)
				                        break;
                              
							  else 
			                  {
				                        //------------------------------------------------------
										for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        {
					                              if(ClusterMatrix[Cluster][Customer] != Client)
					                              {
						                                    
							                                Counter++;
							                                          
							                                if(Counter == 1)
                                                                      fprintf(Write_Model,"%ldX%d_%d",TimeMatrix[ClusterMatrix[Cluster][Customer]][Client],ClusterMatrix[Cluster][Customer],Client);
                                                                      
															else
							                                          fprintf(Write_Model," +\n%ldX%d_%d",TimeMatrix[ClusterMatrix[Cluster][Customer]][Client],ClusterMatrix[Cluster][Customer],Client);                  
		                                          }
	                                    }
                              }
                    }
          } 
          
          //--------------------------------------------------------
          for(Cluster = 1 ; Cluster <= NumberOfClusters ; Cluster++)
	      {
                    //------------------------------------------------------------
					for(Customer = 1 ; Customer <= NumberOfCustomers ; Customer++) 
		            {
                              if(ClusterMatrix[Cluster][Customer] == -1)
				                        break;
                              
							  else 
			                  {
				                        //------------------------------------------------------
										for(Client = 1 ; Client <= NumberOfCustomers ; Client++)
				                        {
					                              if(ClusterMatrix[Cluster][Customer] != Client)
					                              {
							                                if(SecurityLevel >= 0)
															          fprintf(Write_Model," +\n%lfX%d_%d",(SecurityLevel*(double)TimeMatrix[ClusterMatrix[Cluster][Customer]][Client]),ClusterMatrix[Cluster][Customer],Client);  
															
															if(SecurityLevel < 0)
															          fprintf(Write_Model," -\n%lfX%d_%d",-1*(SecurityLevel*(double)TimeMatrix[ClusterMatrix[Cluster][Customer]][Client]),ClusterMatrix[Cluster][Customer],Client);                        
		                                          }
	                                    }
                              }
                    }
          } 
	      
          fprintf(Write_Model," <= %ld\n\n",TMax);
}

// Karar deðiþken türleri belirleniyor.
//------------------------------------------------------------------------------
void Binaries(void)
{
          int Cluster;
		  int Customer_1,Customer_2;
          
          fprintf(Write_Model,"BINARIES\n\n");
          
	      //------------------------------------------------------------------
		  for(Customer_1 = 1 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
	      {
		            //------------------------------------------------------------------
					for(Customer_2 = 1 ; Customer_2 <= NumberOfCustomers ; Customer_2++)
		            {
			                  if(Customer_1 != Customer_2)
			                  {
				                        //if(Control(Customer_1,Customer_2) == 1)
					                              fprintf(Write_Model,"X%d_%d\n",Customer_1,Customer_2);
                              }
                     }
           }
           
           fprintf(Write_Model,"\n");
           
           //------------------------------------------------------------------
		   for(Customer_1 = 2 ; Customer_1 <= NumberOfCustomers ; Customer_1++)
                     fprintf(Write_Model,"Y%d\n",Customer_1);
           
	       fprintf(Write_Model,"\n\nEND");
}
