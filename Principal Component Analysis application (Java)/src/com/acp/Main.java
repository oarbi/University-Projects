package com.acp;

import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;
import Jama.*;

public class Main {

    public static void main(String[] args) {
        String filename = "text.txt";
        int p = numcol(filename);
        int n = numline(filename);
        double[][] tab = readFile(filename,n,p);
        double[][] cent = cen_red(tab,n,p);
        double[][] corre = mat_corr(tab,n,p);
        double[] valprop = valeurpropre(corre,p);
        double[][] comm = commul(valprop,p);
        int nbrfact = choix(comm,p,90);
        //double[][] coord = coordonne(cent,)
        System.out.println("Données Entrées :");
        for(int i=0; i<n;i++){
            for(int j=0;j<p;j++){
                System.out.print(tab[i][j]+"   ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("Données Centrées Reduits :");
        for(int i=0; i<n;i++){
            for(int j=0;j<p;j++){
                System.out.print(cent[i][j]+"   ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("Matrice de correlation:");
        for(int i=0; i<p;i++){
            for(int j=0;j<p;j++){
                System.out.print(corre[i][j]+"   ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("Valeurs Propres:");
        for(int i=0;i<p;i++){
            System.out.print(valprop[i]+"   ");
        }
        System.out.println();
        System.out.println();
        System.out.println("Commulation en pourcentage:");
        for(int i=0; i<p;i++){
            for(int j=0;j<2;j++){
                System.out.print(comm[i][j]+"   ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("Nombre de composante a choisir:");
        System.out.println(nbrfact);

    }

    public static double[][] readFile(String fn,int n,int p){
        FileInputStream fis=null;
        Scanner sc;
        double[][] mat=new double[n][p];
        try{
            fis = new FileInputStream(new File(fn));
            sc = new Scanner(fis);
            for(int i=0; i<n;i++){
                for(int j=0;j<p;j++){
                    mat[i][j]= sc.nextDouble();
                }
            }
            fis.close();
            return mat;
        }
        catch (IOException exception)
        {
            System.out.println ("Erreur lors de la lecture : " + exception.getMessage());
            return null;
        }
    }

    public static int numcol(String fn){
        FileInputStream fis=null;
        Scanner sc;
        try{
            fis = new FileInputStream(new File(fn));
            sc = new Scanner(fis);
            int nbr = sc.nextLine().split(" ").length;
            fis.close();
            return nbr;
        }
        catch (IOException exception)
        {
            System.out.println ("Erreur lors de la lecture : " + exception.getMessage());
            return -1;
        }
    }

    public static int numline(String fn){
        LineNumberReader lnr= null;
        int nbr = 0;
        try{
            lnr = new LineNumberReader(new FileReader(fn));
            while(true){
                if(lnr.readLine() != null){
                    nbr++;
                }else{
                    break;
                }
            }
            return nbr;
        }
        catch (IOException exception)
        {
            System.out.println ("Erreur lors de la lecture : " + exception.getMessage());
            return -1;
        }
    }

    public static double moy(double[][] mat,int j,int n){
        double som=0;
        for(int i=0;i<n;i++){
            som += mat[i][j];
        }
        return som/n;
    }

    public static double covariance(double[][] mat,int col1,int col2,int n){
        double som = 0;
        double moy1 = moy(mat,col1,n);
        double moy2 = moy(mat,col2,n);
        for(int i=0; i<n;i++){
            som += ((mat[i][col1]-moy1)*(mat[i][col2]-moy2));
        }
        return som/n;
    }

    public static double[][] cen_red(double[][] mat,int n,int p){
        double[][] res = new double[n][p];
        double moyx=0;
        DecimalFormat df = new DecimalFormat("#.####");
        for(int j=0;j<p;j++){
            moyx = moy(mat,j,n);
            for(int i=0; i<n;i++){
                res[i][j]= Double.valueOf(df.format((mat[i][j]-moyx)/(Math.sqrt(covariance(mat,j,j,n)))));
            }
        }
        return res;
    }

    public static double correlation(double[][] mat,int var1,int var2,int n){
        double som = 0;
        for(int i=0;i<n ;i++){
            som += (mat[i][var1]*mat[i][var2]);
        }
        return som/n;
    }
    public static double[][] mat_corr(double[][] mat,int n,int p){
        double[][] res = new double[p][p];
        double[][] cent = cen_red(mat,n,p);
        DecimalFormat df = new DecimalFormat("#.####");
        for(int i=0;i<p;i++){
            for(int j=0;j<p;j++){
                res[i][j]= Double.valueOf(df.format(correlation(cent,i,j,n)));
            }
        }
        return res;
    }

    public static double[] valeurpropre(double[][] mat,int p){
        Matrix m = new Matrix(p,p);
        double[] res = new double[p];
        for(int i=0;i<p;i++){
            for(int j=0;j<p;j++){
                m.set(i,j,mat[i][j]);
            }
        }
        DecimalFormat df = new DecimalFormat("#.####");
        EigenvalueDecomposition vp = m.eig();
        for(int i = 0;i<p;i++){
            res[i] = Double.valueOf(df.format(vp.getRealEigenvalues()[p-i-1]));
        }
        return res;
    }

    public static double[][] commul(double[] vect,int p){
        double[][] res = new double[p][2];
        double som=0;
        DecimalFormat df = new DecimalFormat("#.##");
        for(int i=0;i<p;i++){
            res[i][0] = vect[i];
            res[i][1] = som + Double.valueOf(df.format(((vect[i]/p)*100)));
            som += Double.valueOf(df.format(((vect[i]/p)*100)));
        }
        return res;
    }

    public static int choix(double[][] mat,int p,double limit){
        int ch=0;
        for(int i=0;i<p;i++){
            if(mat[i][1]>= limit){
                ch++;
                return ch;
            }
            ch++;
        }
        return -1;
    }

    public static double[][] coordonne(double[][] matind,double[][] matfac,int n,int p,int nbrfac){
        Matrix ind = new Matrix(matind,n,p);
        Matrix fact = new Matrix(matfac,p,nbrfac);
        Matrix res = ind.times(fact);
        double[][] resFinal = new double[n][nbrfac];
        for(int i=0;i<n;i++){
            for(int j=0;j<nbrfac;j++){
                resFinal[i][j]= res.get(i,j);
            }
        }
        return resFinal;
    }

}