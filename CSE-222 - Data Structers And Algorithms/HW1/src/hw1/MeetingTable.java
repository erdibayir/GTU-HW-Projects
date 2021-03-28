package hw1;
/**
 *MeetingTable class holds the desk which is a product type of company and extends Furniture class.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class MeetingTable extends Furniture {
    private String[] models = {"Sketchup","Wooden","Office","Room","Modern","Steel","Cardboard","Plastic","Mini","Old"};
    private String[] colors = {"Blue","Black","Grey","White"};

    /**
     * Constructor of MeetingTable class take model and color name for each meeting table
     * @param modelName model name of meeting table
     * @param colorName color name of meeting table
     */
    public MeetingTable(String modelName, String colorName) {
        super(modelName, colorName,"Meeting Table");
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
