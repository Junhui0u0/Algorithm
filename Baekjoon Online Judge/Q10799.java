import java.io.*;
import java.util.Stack;


public class Q10799 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        Stack<Character> st=new Stack<>();

        int result=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                st.push('(');
                continue;
            }
            else if(s.charAt(i)==')'){
                st.pop();

                if(s.charAt(i-1)=='('){
                    result+=st.size();
                }
                else result++;
            }
        }
        bw.write(result+"\n");
        bw.flush();
        bw.close();
    }
}
