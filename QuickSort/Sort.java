import java.util.*;
public class Sort{
    public static void BubbleSort(int a[]){
        for(int i=0; i<a.length; i++){
            for(int j=0; j<a.length-i-1; j++){
                if(a[j+1]<a[j]){
                    int tmp=a[j];
                    a[j] = a[j+1];
                    a[j+1] = tmp;
                }
            }
        }
    }
    public static void SelectionSort(int a[]){
        for(int i=0; i<a.length-1; i++){
            int min_idx=i;
            for(int j=i+1; j<a.length; j++){
                if(a[j]<a[min_idx]){
                    min_idx = j;
                }
            }
            if(i!=min_idx){
                int tmp=a[i];
                a[i] = a[min_idx];
                a[min_idx] = tmp;
            }
        }
    }
    public static void Merge(int a[],int l,int m,int r){
        int n1=m-l+1;
        int n2=r-m;
        int[] L1=new int[n1];
        int[] L2=new int[n2];
        for(int i=0; i<n1; i++){
            L1[i] = a[i+l];
        }
        for(int i=0;i<n2;i++){
            L2[i]=a[m+i+1];
        }
        int i=0,j=0,k=l;
        while(i<n1&&j<n2){
            if(L1[i]<=L1[j]){
                a[k++]=L1[i++];
            }else{
                a[k++]=L2[j++];
            }
        }
        while(i<n1){
            a[k++]=L1[i++];
        }
        while(j<n2){
            a[k++]=L2[j++];
        }
    }
    public static void MergeSort(int a[],int l,int r){
        if(l<r){
            int m=(l+r)/2;
            MergeSort(a,l,m);
            MergeSort(a,m+1,r);
            Merge(a,l,m,r);
        }
    }
    public static void InsertionSort(int[] a){
        int n=a.length;
        for(int i=1; i<n; i++){
            int tmp=a[i];
            int j=i-1;
            while(j>=0 && a[j]>tmp){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=tmp;
        }
    }
    public static void main(String[] args) {
        int[] a = new int[]{-1,3,1,0,-9,3,4,12};
        MergeSort(a,0,a.length-1);
        System.out.println(Arrays.toString(a));
    }
}