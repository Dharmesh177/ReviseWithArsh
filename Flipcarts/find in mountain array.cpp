/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarysearchL(int target, MountainArray &mountainArr,int s,int e){
        // int mid=s+e/2;
        while(s<=e){
      int mid=s+(e-s)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid) < target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
    int binarysearchR(int target, MountainArray &mountainArr,int s,int e){
        // int mid=s+e/2;
        while(s<=e){
           int mid=s+(e-s)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid) > target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
      int n=mountainArr.length();
        int s=0,e=n-1;
        int peakEle;
        while(s<e){ // Finding Peak Element
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid+1)>mountainArr.get(mid)){
                s=mid+1;
                peakEle=mid+1;
            }
            else
                e=mid;
        }
        int l=binarysearchL(target,mountainArr,0,peakEle);
         int r=binarysearchR(target,mountainArr,peakEle,n-1);
        return l>=0 ? l : r;
    }
};