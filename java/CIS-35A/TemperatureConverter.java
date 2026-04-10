/*
 * Pranav Mandala
 * Class: CIS 35A
 * Assignment: Lab -1, Project 2
 * Due Date: 4/17/26
 * Date Submitted: 
 * 
 * Program Description: Converts a given temperature in Celsius or
 *                      Fahrenheit to Fahrenheit or Celsius
 */

import java.util.Scanner;

public class TemperatureConverter {
    
    public static void main(String[] args) {
        
        //Declaring variables to hold given and calculated temperatures
        double celsius;
        double fahrenheit;
        double calculatedCelsius;
        double calculatedFahrenheit;
        
        //Creating a scanner object
        Scanner s = new Scanner(System.in);
        
        System.out.printf("=== Temperature Converter ===\n\n");
        
        //Prompting user for celsius input and initializing
        System.out.printf("Enter a temperature in Celsius: ");
        celsius = s.nextDouble();
        
        //Converting celsius to fahrenheit
        calculatedFahrenheit = 32 + celsius * (180.00 / 100.00);
        
        //Outputting celsius and converted fahrenheit
        System.out.printf("%.2f\u00B0C = %.2f\u00B0F\n\n", celsius, calculatedFahrenheit);
        
        //Prompting user for fahrenheit input and intializing
        System.out.printf("Enter a temperature in Fahrenheit: ");
        fahrenheit = s.nextDouble();
        
        //Converting fahrenheit to celsius
        calculatedCelsius = (fahrenheit - 32) * (100.00 / 180.00);
        
        //Outputting fahrenheit and converted celsius
        System.out.printf("%.2f\u00B0F = %.2f\u00B0C", fahrenheit, calculatedCelsius);
        
        s.close();
        
    }
}
