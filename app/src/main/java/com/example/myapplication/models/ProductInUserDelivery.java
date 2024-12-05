package com.example.myapplication.models;

public class ProductInUserDelivery extends Product {
    private String delivery_address;
    private String quantity;
    private String userUid;
    private String deliveryNumber;
    //  address, productName, productPrice, productDescription, imageUri,
    //                                            quantity, userUid, deliveryNumber, productCode
    public ProductInUserDelivery(String product_code, String product_name, String product_price,
                                 String product_description, String imageUri, String quantity,
                                 String delivery_address, String userUid, String deliveryNumber) {
        super(product_code, product_name, product_price, product_description, imageUri);
        this.quantity = quantity;
        this.delivery_address = delivery_address;
        this.userUid = userUid;
        this.deliveryNumber = deliveryNumber;
    }

    public ProductInUserDelivery() {
    }

    public String getDelivery_address() {
        return delivery_address;
    }

    public void setDelivery_address(String delivery_address) {
        this.delivery_address = delivery_address;
    }

    public String getUserUid() {
        return userUid;
    }

    public void setUserUid(String userUid) {
        this.userUid = userUid;
    }

    public String getDeliveryNumber() {
        return deliveryNumber;
    }

    public void setDeliveryNumber(String deliveryNumber) {
        this.deliveryNumber = deliveryNumber;
    }

    public String getQuantity() {
        return quantity;
    }

    public void setQuantity(String quantity) {
        this.quantity = quantity;
    }
}
