/* package codechef; // don't place package name! */

import java.util.*;

import java.lang.*;

import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */

class Chef_and_Bulb_Invention
{
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static class FastWriter {
        private final BufferedWriter bw;
        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }
        public void print(Object object) throws IOException {
            bw.append("").append(String.valueOf(object));
        }
        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }
        public void close() throws IOException {
            bw.close();
        }
    }
    public static void main(String[] args) throws java.lang.Exception{
        // your code goes here
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            int p = in.nextInt();
            int k = in.nextInt();
            long sum = 0;
            if ((n - ((n / k) * k)) <= (p % k)) {
                sum += (long) Math.ceil(((float) n) / k) * (n - ((long) (n / k) * k));
                sum += (n / k) * ((p % k) - (n - ((long) (n / k) * k))) + (p / k) + 1;
            } else {
                sum += (long) Math.ceil(((float) n) / k) * (p % k) + (p / k) + 1;
            }
            out.println(sum);
        }
        out.close();
    }
}
