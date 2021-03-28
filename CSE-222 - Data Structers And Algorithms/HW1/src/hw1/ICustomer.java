package hw1;

/**
 * Customer Interface for Customer class
 */
public interface ICustomer {
    void showOrders();
    void showListOfProduct(Company company);
    void searchProduct(Company company,Furniture searchObject);
    <T> boolean  searchProductHelper(Branch currentBranch,MyArray<T> array,Furniture searchObject);
}
