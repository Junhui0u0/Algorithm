//hashset => 중복 제거
import java.io.*;
import java.util.*;

public class Q1764 {
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        HashSet<String> set=new HashSet<>();            //HashSet

        String[] inputs=br.readLine().split(" ");
        int n=Integer.parseInt(inputs[0]);
        int m=Integer.parseInt(inputs[1]);
        for(int i=0;i<n;i++){
            set.add(br.readLine());
        }

        ArrayList<String> result=new ArrayList<>();
        for(int i=0;i<m;i++){
            String tmp=br.readLine();
            if(set.contains(tmp)) result.add(tmp);      //
        }

        Collections.sort(result);

        bw.write(result.size()+"\n");
        for(String s:result){
            bw.write(s+"\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
