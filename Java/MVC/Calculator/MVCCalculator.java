/*
    Referencess:
    "Derek Banas"
    https://www.youtube.com/watch?v=dTVVa2gfht8&list=RDCMUCwRXb5dUK4cvsHbx-rGzSgw&start_radio=1&t=784s

*/
package MVC.Calculator;

public class MVCCalculator {
    public static void main(String[] args) {
        
        CalculatorView theView = new CalculatorView();

        CalculatorModel theModel = new CalculatorModel();

        new CalculatorController(theView, theModel);

        theView.setVisible(true);
    }
}
