package com.example.ecom_proj.repo;

import com.example.ecom_proj.model.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface ProductRepo extends JpaRepository<Product, Integer>
{
    @Query("SELECT p FROM Product p WHERE " +
            "LOWER(p.brand) LIKE LOWER(concat('%', :keyword, '%')) OR " +
            "LOWER(p.category) LIKE LOWER(concat('%', :keyword, '%')) OR " +
            "LOWER(p.description) LIKE LOWER(concat('%', :keyword, '%')) OR " +
            "LOWER(p.name) LIKE LOWER(concat('%', :keyword, '%'))")
    List<Product> selectProducts(String keyword);
}
