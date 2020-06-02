#include<iostream> 


void drawOneTicks(int tickLength, int tickLabel = -1){
	for(int i = 0;i<tickLength;++i){
		std::cout<<"-";
	}
	if(tickLabel>=0)std::cout<<tickLabel;
	std::cout<<"\n";
}
										
void drawTicks(int tickLength){ 	//the central tick length-1		
	if(tickLength>0){
		drawTicks(tickLength-1);
		drawOneTicks(tickLength);
		drawTicks(tickLength-1);
	}
		
}

void drawRuler(int nInches,int majorTickLength){
	drawOneTicks(majorTickLength,0);
	for (int i = 1;i<=nInches;++i){
		drawTicks(majorTickLength-1);
		drawOneTicks(majorTickLength,i);
	}
}

int main(){
	int inches,maxTicks;
	std::cout<<"Enter a number of Inches and the Maximum number of ticks -->";
	std::cin>>inches>>maxTicks;
	drawRuler(inches,maxTicks);
	return 0;
}
