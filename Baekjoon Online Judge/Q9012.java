import java.io.*;
import java.util.Stack;

public class Q9012 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        int num=Integer.parseInt(br.readLine());

        Stack<Character> s=new Stack<>();

        for(int i=0;i<num;i++){
            String str=br.readLine();
            int length=str.length();

            for(int j=0;j<length;j++){
                char ch=str.charAt(j);

                if(ch=='('){
                    s.push(ch);
                }
                else{
                    int size=s.size();
                    if(size==0){
                        s.push(ch);
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
            }
            if(s.isEmpty()){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
            s.clear();
        }
    }
}
