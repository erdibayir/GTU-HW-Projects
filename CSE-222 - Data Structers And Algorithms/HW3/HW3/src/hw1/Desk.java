package hw1;
/**
 *Desk class holds the desk which is a product type of company and extends Furniture class.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class Desk extends Furniture {

    private String[] models = {"Computer","School","Wooden","Office","Room"};
    private String[] colors = {"Blue","Black","Grey","White"};

    /**
     * Constructor of Desk class take model and color name for each desk
     * @param modelName model name of desk
     * @param colorName color name of desk
     */
    public Desk(String modelName, String colorName) {
        super(modelName, colorName,"Desk");
    }

    /**
     * Getter of models array
     * @return models array
     */
    public String[] getModels() {
        return models;
    }

    /**
     * Setter  of models array
     * @param models models array
     */
    public void setModels(String[] models) {
        this.models = models;
    }

    /**
     * Getter of colors array
     * @return colors array
     */
    public String[] getColors() {
        return colors;
    }

    /**
     * Setter of colors array
     * @param colors array
     */
    public void setColors(String[] colors) {
        this.colors = colors;
    }
}
