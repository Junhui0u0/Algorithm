//heap -> "priority queue"
import java.io.*;
import java.util.PriorityQueue;

public class Q1927 {
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        PriorityQueue<Integer> q=new PriorityQueue<>();

        int n=Integer.parseInt(br.readLine());

        for(int i=0;i<n;i++){
            int num=Integer.parseInt(br.readLine());
            if(num!=0){
                q.add(num);
            }
            else if(q.isEmpty()){
                bw.write("0\n");
            }
            else{
                bw.write(q.poll()+"\n");        //반환 후 삭제
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
