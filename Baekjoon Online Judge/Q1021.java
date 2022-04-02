//deque (Doubly LinkedList)
import java.io.*;
import java.util.*;

public class Q1021 {
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        LinkedList<Integer> deque=new LinkedList<Integer>();    //deque
        int ans=0;

        String[] inputs=br.readLine().split(" ");
        int n=Integer.parseInt(inputs[0]);
        int m=Integer.parseInt(inputs[1]);

        for(int i=1;i<=n;i++){
            deque.add(i);
        }
        String[] inputs2=br.readLine().split(" ");
        for(int i=0;i<m;i++){
            int num=Integer.parseInt(inputs2[i]);

            int findIdx=deque.indexOf(num);
            int middleIdx=0;
            if(deque.size()%2==0){
                middleIdx=deque.size()/2-1;
            }
            else{
                middleIdx=deque.size()/2;
            }

            if(findIdx<=middleIdx){
                for(int j=0;j<findIdx;j++){
                    int tmp=deque.pollFirst();
                    deque.addLast(tmp);
                    ans++;
                }
            }
            else{
                for(int j=0;j<deque.size()-findIdx;j++){
                    int tmp=deque.pollLast();
                    deque.addFirst(tmp);
                    ans++;
                }
            }
            deque.pollFirst();
        }
        bw.write(ans+"\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
