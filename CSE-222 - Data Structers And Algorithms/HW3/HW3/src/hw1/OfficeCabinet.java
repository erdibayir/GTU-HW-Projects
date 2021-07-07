package hw1;
/**
 *OfficeCabinet class holds the desk which is a product type of company and extends Furniture class.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class OfficeCabinet extends Furniture {
    private String[] models = {"Glass","Wooden","Storage","Room","Modern","Steel","Cardboard",
            "Plastic","Mini","Old","Library","Creative"};

    /**
     * Constructor of MeetingTable class take model and color name for each meeting table
     * @param modelName model name of office cabinet
     */
    public OfficeCabinet(String modelName) {
        super(modelName, "Uncolored","Office Cabinet");
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
}
