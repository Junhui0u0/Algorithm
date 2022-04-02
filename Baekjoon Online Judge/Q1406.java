//ListIterator
import java.io.*;
import java.util.*;

public class Q1406 {
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        LinkedList<Character> list=new LinkedList<Character>();

        String str=br.readLine();
        int n=Integer.parseInt(br.readLine());

        for(int i=0;i<str.length();i++){
            list.add(str.charAt(i));
        }

        ListIterator<Character> iter=list.listIterator();        //key point
        while(iter.hasNext()){
            iter.next();
        }

        for(int i=0;i<n;i++){
            String cmd=br.readLine();
            char c=cmd.charAt(0);           //

            switch(c){
                case 'L':
                    if(iter.hasPrevious()){
                        iter.previous();
                    }
                    break;
                case 'D':
                    if(iter.hasNext()){
                        iter.next();
                    }
                    break;
                case 'B':
                    if(iter.hasPrevious()){
                        iter.previous();
                        iter.remove();
                    }
                    break;
                case 'P':
                    char t=cmd.charAt(2);
                    iter.add(t);
                    break;
                default:
                    break;
            }
        }
        for(Character chr:list){
            bw.write(chr);
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
