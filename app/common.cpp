
int clamp(int val, int max, int min=0){
    if(val > max-1){
        return max-1;
    }else if(val < min){
        return min;
    }else{
        return val;
    }
}