#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//declare global 
int *sequence = NULL;
int sequenceSize;

void optionOne(){                                                        
	//prompt for sequence size
	printf("Enter size of sequence: ");
	scanf("%d", &sequenceSize);
	
	//allocate memory for the sequence of traversed tracks
	sequence = (int*)malloc(sequenceSize * sizeof(int));
	
	//prompt for starting track, store in index 0
	printf("Enter starting track ");
	scanf("%d", &sequence[0]);
	
	//prompt for sequence of tracks to seek, store in index 1 to sequenceSize - 1
	printf("Enter sequence of tracks to seek: ");
	for(int i = 1; i <= sequenceSize-1; i++){
		scanf("%d", &sequence[i]);
	}
	
	return;
	
}//option1

void optionTwo(){
	//declare local variables
	int totalDistance = sequence[0];
	
	printf("\nTraversed sequence: ");
	//calculate total distance of traversed track
	for(int i = 1; i <= sequenceSize - 1; i++){
		totalDistance += abs(sequence[i] - sequence[i-1]);
		printf("%d ", sequence[i]);
	}
	
	//print total distance of traversal
	printf("\nThe distance of the traversed track is: %d", totalDistance);
	
	return;
	
}

void optionThree(){
	//declare local variables
	int currentTrack = sequence[0]; 
	int totalDistance = sequence[0];
	int numDone = 1;
	int shortest = 0;
	int shortestIndex = 0;
	int* checked = (int*)calloc(sequenceSize, sizeof(int));
	int atLeastOne = 0;
	
	//begin printing sequence of traversal
	printf("\nTraversed track: %d ", sequence[0]);
	
	while(numDone < sequenceSize){
		shortest = INT_MAX;
		
		//calculate total distance of traversed track
		for(int i = 1; i <= sequenceSize - 1; i++){
			//if not already traversed
			if(checked[i] == 0){
				//if distance to traverse is shorter than current shortest distance 
				if(abs(sequence[i] - currentTrack) < shortest){
					
					//set current shortest distance and index of the track w/ shortest distance
					shortest = abs(sequence[i] - currentTrack);
					shortestIndex = i;
				}
			}
		}
		//set done value for track w/ shortest distance to 1(mark as traversed)
		checked[shortestIndex] = 1;
		//increment number of tracks that have been traversed
		numDone++;
		//update total distance traversed
		totalDistance += shortest;
		//set current track to new position, print position
		currentTrack = sequence[shortestIndex];
		printf("%d ", sequence[shortestIndex]);
		
	}
			
	//print distance travelled
	printf("\nThe distance of the traversed track is: %d", totalDistance);
	
	return;
}

void optionFour(){
    int direction;
    
	//prompt for initial direction(0=decreasing, 1=increasing)
	printf("Enter initial direction (0=decreasing, 1=increasing): ");
	scanf("%d", &direction);
	
	//declare local variables
	int currentTrack = sequence[0]; 
	int totalDistance = sequence[0];
	int numDone = 1;
	int shortest = 0;
	int shortestIndex = 0;
	int* checked = (int*)calloc(sequenceSize, sizeof(int));
	int atLeastOne = 0;
	
	//begin printing sequence of traversal
	printf("\nTraversed track: %d ", sequence[0]);
	
	
	while(numDone < sequenceSize){
		shortest = INT_MAX;
		atLeastOne = 0;
		
		//calculate total distance of traversed track
		for(int i = 1; i <= sequenceSize - 1; i++){
			//if not already traversed
			if(checked[i] == 0){
				//if distance to traverse is shorter than current shortest distance 
				if(abs(sequence[i] - currentTrack) < shortest){
					if(((sequence[i] - currentTrack > 0) && (direction == 1))||((sequence[i] - currentTrack < 0) && (direction == 0)))
					{
						//set current shortest distance and index of the track w/ shortest distance
						shortest = abs(sequence[i] - currentTrack);
						shortestIndex = i;
						atLeastOne = 1;
					}
			
				}
			}
		}
		if(atLeastOne == 1){
			//set done value for track w/ shortest distance to 1(mark as traversed)
			checked[shortestIndex] = 1;
			//increment number of tracks that have been traversed
			numDone++;
			//update total distance traversed
			totalDistance += shortest;
			//set current track to new position, print position
			currentTrack = sequence[shortestIndex];
			printf("%d ", sequence[shortestIndex]);
			
		}else{
			direction = 1 - direction;
		}
		
	}
			
	//print distance travelled
	printf("\nThe distance of the traversed track is: %d ", totalDistance);
	
	return;
	
}

void optionFive(){
	
	
	//declare local variables
	int currentTrack = sequence[0]; 
	int totalDistance = sequence[0];
	int numDone = 1;
	int shortest = 0;
	int shortestIndex = 0;
	int* checked = (int*)calloc(sequenceSize, sizeof(int));
	int endReached = 0;
	int atLeastOne = 0;
	
	
	//begin printing sequence of traversal
	printf("\nTraversed track: %d ", sequence[0]);
	
	
	while(numDone < sequenceSize){
		shortest = INT_MAX;
		atLeastOne = 0;
		
		//calculate total distance of traversed track
		for(int i = 1; i <= sequenceSize - 1; i++){
			//if not already traversed
			if(checked[i] == 0){
				//if distance to traverse is shorter than current shortest distance 
				if(abs(sequence[i] - currentTrack) < shortest){
					if((sequence[i] - currentTrack) > 0)
					{
						//set current shortest distance and index of the track w/ shortest distance
						shortest = (sequence[i] - currentTrack);
						shortestIndex = i;
						atLeastOne = 1;
					}
			
				}
			}
		}
		if(atLeastOne == 1){
			if(endReached == 0){
				totalDistance += shortest;
			}else{
				totalDistance -= shortest;
				endReached = 0;
			}
			//set done value for track w/ shortest distance to 1(mark as traversed)
			checked[shortestIndex] = 1;
			
			//increment number of tracks that have been traversed
			numDone++;

			//set current track to new position, print position
			currentTrack = sequence[shortestIndex];
			printf("%d ", sequence[shortestIndex]);
			
		}else{
			totalDistance += currentTrack;
			currentTrack = 0;
			endReached = 1;
		}
		
	}
			
	//print distance travelled
	printf("\nThe distance of the traversed track is: %d", totalDistance);
	
	return;
}

void optionSix(){
	//if sequence is not null, free sequence
	if(sequence != NULL){
		free(sequence);
	}
	return;
}

int main(){
	int choice = 0;
	
	while(choice != 6){
		printf("\n\nDisk Scheduling\n");
		printf("--------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Calculate distance to traverse tracks using FIFO\n");
		printf("3) Calculate distance to traverse tracks using SSTF\n");
		printf("4) Calculate distance to traverse tracks using Scan\n");
		printf("5) Calculate distance to traverse tracks using C-Scan\n");
		printf("6) Quit program and free memory\n");
		printf("\nEnter selection: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: 
			    optionOne();
			    break;
			case 2: 
			    optionTwo();
			    break;
			case 3: 
			    optionThree();
			    break;
			case 4: 
			    optionFour();
			    break;
			case 5: 
			    optionFive();
			    break;
			case 6: 
			    optionSix();
			    printf("\nQuitting Program...");
			    break;
		}
	}
	return 1;
}//end main