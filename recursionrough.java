public class recursionrough {
    public static void printno(int n){
        if(n==0){
            return;
        }
        System.out.println(n);
        printno(n-1);
        if(n==1){

            System.out.println("here n==1");
        }
        if(n==2){
            System.out.println("here n==2");
        }
        if(n==3){
            System.out.println("here n==3");
        }
        if(n==4){
            System.out.println("here n==4");
        }
        if(n==5){
            System.out.println("here n==5");
        }
        if(n==6){
            System.out.println("here n==6");
        }
        if(n==7){
            System.out.println("here n==7");
        }
        if(n==8){
            System.out.println("here n==8");
        }
        //the function will return to the previous function call after these whole function (i.e all the if statements and till } gets executed) 
    }
    public static void main(String[] args) {
        printno(8);
    }
}
