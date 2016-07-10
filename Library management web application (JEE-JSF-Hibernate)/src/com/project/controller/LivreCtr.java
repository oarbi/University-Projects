package com.project.controller;

import java.util.List;

import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;
import javax.faces.context.FacesContext;

import org.hibernate.HibernateException;

import com.project.dao.LivreDao;
import com.project.model.Livre;




@ManagedBean(name="bookCtr")
@SessionScoped
public class LivreCtr 
{
	private LivreDao bookDao = new LivreDao();
	private Livre book = new Livre();
	private Livre bok = new Livre();
	private List<Livre> books;
	private List<Livre> booksSelection;
	
	public String saveBook()
	{
		try
		{
			bookDao.persist(book);
			addMessageInfo("OK !!","Success");
			return "savesuccess";
		}
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","L'utilisateur existe ou Champ obligatoire vide !!");
			return "savefail";
		}
	}
	public void oneBookSelection()
	{
		try
		{
			bok = booksSelection.get(0);
		}
		catch(IndexOutOfBoundsException e)
		{
			//Rien faire
		}
		
	}
	
	public String changeBook()
	{
		try
		{
			bookDao.update(bok);
			addMessageInfo("OK !!","Success");
			return "savesuccess";
		} 
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","L'utilisateur existe ou Champ obligatoire vide !!");
			return "savefail";
		}
	}
	public String deleteBook()
	{
		try
		{
			for(Livre b: booksSelection)
				bookDao.delete(b);
			return "delete";
		}
		catch(HibernateException e)
		{
			return "notdelete";
		}
	}
	
	public void listBook()
	{
		books = bookDao.findAll();
	}
	
	public void addMessageWarn(String summary, String detail) 
	{
        FacesMessage message = new FacesMessage(FacesMessage.SEVERITY_WARN, summary, detail);
        FacesContext.getCurrentInstance().addMessage(null, message);
    }
	public void addMessageInfo(String summary, String detail) 
	{
        FacesMessage message = new FacesMessage(FacesMessage.SEVERITY_INFO, summary, detail);
        FacesContext.getCurrentInstance().addMessage(null, message);
    }
	public LivreDao getBookDao() {
		return bookDao;
	}
	public void setBookDao(LivreDao bookDao) {
		this.bookDao = bookDao;
	}
	public Livre getBook() {
		return book;
	}
	public void setBook(Livre book) {
		this.book = book;
	}
	public Livre getBok() {
		return bok;
	}
	public void setBok(Livre bok) {
		this.bok = bok;
	}
	public List<Livre> getBooks() {
		return books;
	}
	public void setBooks(List<Livre> books) {
		this.books = books;
	}
	public List<Livre> getBooksSelection() {
		return booksSelection;
	}
	public void setBooksSelection(List<Livre> booksSelection) {
		this.booksSelection = booksSelection;
	}
	
}
