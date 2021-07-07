package hw1;

/**
 *Chair Class holds the chair which is a product type of company and extends Furniture class.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class Chair extends Furniture {
    private String[] models = {"Plastic","Wooden","Steel","Cardboard","Supreme","Office","Modern"};
    private String[] colors = {"Blue","Black","Yellow","Grey","White"};

    /**
     * Constructor of chair class take model and color name for each chair
     * @param modelName model name of chair
     * @param colorName color name of chair
     */
    public Chair(String modelName, String colorName) {
        super(modelName, colorName,"Chair");
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
