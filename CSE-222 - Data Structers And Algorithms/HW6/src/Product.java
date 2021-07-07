import java.util.Random;

/**
 * @author Erdi Bayır
 * @since 26-05-2021
 * Product Class Implementation.It implements Comparable interface.
 */
public class Product implements Comparable {
    /**
     * Trader object of product owns
     */
    private Trader ownTrader;
    /**
     * id of product
     */
    private String id;
    /**
     * category of product
     */
    private String category;
    /**
     * name of product
     */
    private String name;
    /**
     * description of product
     */
    private String description;
    /**
     * price of product
     */
    private String price;
    /**
     * Discount price of product
     */
    private String DiscountPrice;

    /**
     * Product 7 parameter constructor to create Product object
     * @param ownTrader Trader object of product owns
     * @param id id of product
     * @param name name of product
     * @param category category of product
     * @param price price of product
     * @param discountPrice discount price of product
     * @param description description of product
     */
    public Product(Trader ownTrader, String id, String name, String category, String price, String discountPrice, String description) {
        this.ownTrader = ownTrader;
        this.id = id;
        this.category = category;
        this.name = name;
        this.description = description;
        this.price = price;
        DiscountPrice = discountPrice;
    }

    /**
     * Product 6 parameter constructor to create Product object
     * @param ownTrader Trader object of product owns
     * @param name name of product
     * @param category category of product
     * @param price price of product
     * @param discountPrice discount price of product
     * @param description description of product
     */
    public Product(Trader ownTrader, String name, String category, String price, String discountPrice, String description) {
        this.ownTrader = ownTrader;
        this.category = category;
        this.name = name;
        this.description = description;
        this.price = price;
        DiscountPrice = discountPrice;
        id = createUniqueId();
    }

    /**
     * Create uniq id for products
     * @return
     */
    private String createUniqueId(){
        String SALTCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        StringBuilder salt = new StringBuilder();
        Random rnd = new Random();
        while (salt.length() < 16) { // length of the random string.
            int index = (int) (rnd.nextFloat() * SALTCHARS.length());
            salt.append(SALTCHARS.charAt(index));
        }
        String saltStr = salt.toString();
        return saltStr;
    }

    /**
     * toString override method
     * @return Return Product information as a string
     */
    @Override
    public String toString() {
        return ownTrader.getName() + ";" + id + ";"   + name + ";"  + category + ";" + price + ";" + DiscountPrice + ";"  + description;
    }

    /**
     * Return Trader of Product
     * @return Return trader of product
     */
    public Trader getOwnTrader() {
        return ownTrader;
    }

    /**
     * Set Trader of Product
     * @param ownTrader new Trader object to set Product
     */
    public void setOwnTrader(Trader ownTrader) {
        this.ownTrader = ownTrader;
    }
    /**
     * Return id of Product
     * @return Return id of product
     */
    public String getId() {
        return id;
    }

    /**
     * Set id of Product
     * @param id new id value for product
     */
    public void setId(String id) {
        this.id = id;
    }
    /**
     * Return category of Product
     * @return Return category of product
     */
    public String getCategory() {
        return category;
    }

    /**
     * Set category of Product
     * @param category new category value for product
     */
    public void setCategory(String category) {
        this.category = category;
    }
    /**
     * Return name of Product
     * @return Return name of product
     */
    public String getName() {
        return name;
    }
    /**
     * Set name of Product
     * @param name new name value for product
     */
    public void setName(String name) {
        this.name = name;
    }
    /**
     * Return description of Product
     * @return Return description of product
     */
    public String getDescription() {
        return description;
    }
    /**
     * Set description of Product
     * @param description new description value for product
     */
    public void setDescription(String description) {
        this.description = description;
    }
    /**
     * Return price of Product
     * @return Return price of product
     */
    public String getPrice() {
        return price;
    }
    /**
     * Set price of Product
     * @param price new description value for product
     */
    public void setPrice(String price) {
        this.price = price;
    }
    /**
     * Return discount price of Product
     * @return Return discount price of product
     */
    public String getDiscountPrice() {
        return DiscountPrice;
    }
    /**
     * Set discount price of Product
     * @param discountPrice new discount price value for product
     */
    public void setDiscountPrice(String discountPrice) {
        DiscountPrice = discountPrice;
    }

    /**
     * compareTo override method
     * @param o Comparable object for compare with product
     * @return Return true if compare is successfully otherwise 0
     */
    @Override
    public int compareTo(Object o) {
        if(o.toString().equals(toString()));
            return 0;

    }
}
