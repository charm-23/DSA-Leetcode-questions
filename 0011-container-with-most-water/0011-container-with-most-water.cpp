class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(); 
        int i=0; 
        int j=n-1; 
        int area=0; 
        while(i<j){
            int breadth= j-i; 
            int length= min(height[i], height[j]); 
            area= max(area, length * breadth);
            //1. shift the minimum height pointer as it determines the height(otherwise height remains same or less)and width also less so area will always be less tada. 
            //2.width will always decrease on moving the pointer hence choose max height and move the pointer with minimum height to keep max area; 
            if(height[i]<= height[j]) i++; 
            else{
                j--;
            }
            
        }
    return area; 
    }
};