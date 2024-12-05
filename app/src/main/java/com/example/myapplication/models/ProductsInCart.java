package com.example.myapplication.models;

public class ProductsInCart extends Product {
    private String quantity;

    public ProductsInCart(String product_code, String product_name, String product_price,
                         String product_description, String imageUri, String quantity) {
        super(product_code, product_name, product_price, product_description, imageUri);
        this.quantity = quantity;
    }

    public ProductsInCart() {
    }

    public String getQuantity() {
        return quantity;
    }

    public void setQuantity(String quantity) {
        this.quantity = quantity;
    }
}
