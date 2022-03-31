import java.util.*;

public class Q1920 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        int m=sc.nextInt();
        for(int i=0;i<m;i++){
            int num=sc.nextInt();
            int left=0;
            int right=arr.length-1;
            boolean flag=false;
            
            while(left<=right){
                int midIdx=(left+right)/2;
                int midVal=arr[midIdx];
                if(midVal>num){
                    right=midIdx-1;
                }
                else if(midVal<num){
                    left=midIdx+1;
                }
                else{       //찾음
                    flag=true;
                    System.out.println("1");
                    break;
                }
            }
            if(flag==false){
                System.out.println("0");
            }
        }
    }
}
