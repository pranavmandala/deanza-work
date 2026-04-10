/*
 * Pranav Mandala
 * Class: CIS 35A
 * Assignment: Lab -1, Project 1
 * Due Date: 4/17/26
 * Date Submitted: 
 * 
 * Program Description: Creates a formatted customer bill for five products,
 *                      taking in requested quantities, calculating totals, 
 *                      and adding sales tax.
 */

import java.util.Scanner;

public class CustomerBill {
    
    public static void main(String[] args) {

        // Declaring constants
        final double PRICE_TV = 400.00;
        final double PRICE_VCR = 220.00;
        final double PRICE_REMOTE = 35.20;
        final double PRICE_CD = 300.00;
        final double PRICE_TAPE = 150.00;
        final double TAX_RATE = 0.0825;

        // Declaring variables for quantities
        int tv;
        int vcr;
        int remote;
        int cd;
        int tape;

        // Declaring variables for totals of each item
        double tvTotal;
        double vcrTotal;
        double remoteTotal;
        double cdTotal;
        double tapeTotal;

        // Declaring variables for overall totals and tax
        double subtotal;
        double purchaseTax;
        double purchaseTotal;

        // Creating a scanner object
        Scanner s = new Scanner(System.in);

        // Prompting user for input and initializing quantity variables
        System.out.printf("How many TV's were sold? ");
        tv = s.nextInt();
        System.out.printf("How many VCR's were sold? ");
        vcr = s.nextInt();
        System.out.printf("How many Remote Controller's were sold? ");
        remote = s.nextInt();
        System.out.printf("How many CD Player's were sold? ");
        cd = s.nextInt();
        System.out.printf("How many Tape Recorder's were sold? ");
        tape = s.nextInt();

        // Calculating totals for each item
        tvTotal = tv * PRICE_TV;
        vcrTotal = vcr * PRICE_VCR;
        remoteTotal = remote * PRICE_REMOTE;
        cdTotal = cd * PRICE_CD;
        tapeTotal = tape * PRICE_TAPE;

        // Calculating totals and tax for purchase
        subtotal = tvTotal + vcrTotal + remoteTotal + cdTotal + tapeTotal;
        purchaseTax = subtotal * TAX_RATE;
        purchaseTotal = subtotal + purchaseTax;

        // Formatting and outputting data
        System.out.printf("====================================================\n");
        System.out.printf("%5s   %-21s%10s%13s\n", "QTY", "DESCRIPTION", "UNIT PRICE", "TOTAL PRICE");
        System.out.printf("----------------------------------------------------\n");
        System.out.printf("%5d   %-21s%9.2f%12.2f\n", tv, "TV", PRICE_TV, tvTotal);
        System.out.printf("%5d   %-21s%9.2f%12.2f\n", vcr, "VCR", PRICE_VCR, vcrTotal);
        System.out.printf("%5d   %-21s%9.2f%12.2f\n", remote, "Remote Controller", PRICE_REMOTE, remoteTotal);
        System.out.printf("%5d   %-21s%9.2f%12.2f\n", cd, "CD Player", PRICE_CD, cdTotal);
        System.out.printf("%5d   %-21s%9.2f%12.2f\n", tape, "Tape Recorder", PRICE_TAPE, tapeTotal);
        System.out.printf("----------------------------------------------------\n");
        System.out.printf("%40s%10.2f\n", "SUBTOTAL:", subtotal);
        System.out.printf("%40s%10.2f\n", "TAX:", purchaseTax);
        System.out.printf("%40s%10.2f\n", "TOTAL:", purchaseTotal);
        System.out.printf("====================================================\n");

        s.close();

    }
}