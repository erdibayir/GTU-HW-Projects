package hw1;

/**
 * Furniture Class.It keeps model and color name of products.
 * @author Erdi Bayır
 * @since 13.03.2021
 */
public class Furniture {
    protected String modelName;
    protected String colorName;
    protected String typeProduct;

    /**
     * Constructor of Furniture class take model and color name and type of product.
     * @param modelName model name of furniture
     * @param colorName color name of furniture
     * @param typeProduct type of product
     */
    public Furniture(String modelName, String colorName,String typeProduct) {
        this.modelName = modelName;
        this.colorName = colorName;
        this.typeProduct = typeProduct;
    }

    /**
     * Getter of product type
     * @return product type
     */
    public String getTypeProduct() {
        return typeProduct;
    }

    /**
     * Setter of product type
     * @param typeProduct product type
     */
    public void setTypeProduct(String typeProduct) {
        this.typeProduct = typeProduct;
    }

    /**
     * Getter of model name
     * @return model name
     */
    public String getModelName() {
        return modelName;
    }

    /**
     * Setter of model name
     * @param modelName model name
     */
    public void setModelName(String modelName) {
        this.modelName = modelName;
    }

    /**
     * Getter of color name
     * @return color name
     */
    public String getColorName() {
        return colorName;
    }

    /**
     * Setter of Color Name
     * @param colorName color name
     */
    public void setColorName(String colorName) {
        this.colorName = colorName;
    }

    /**
     * Override of toString function
     * @return type of product model name and color name
     */
    @Override
    public String toString() {
        return typeProduct + " " +  modelName + " " + colorName;
    }
}
