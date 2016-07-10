package com.project.controller;

import java.util.List;

import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;
import javax.faces.context.FacesContext;
import org.hibernate.HibernateException;


import com.project.dao.UtilisateurDao;
import com.project.model.Utilisateur;




@ManagedBean(name="userCtr")
@SessionScoped
public class UtilisateurCtr 
{
	private UtilisateurDao userDao = new UtilisateurDao();
	private Utilisateur user = new Utilisateur();
	private Utilisateur usr = new Utilisateur();
	private List<Utilisateur> users ;
	private List<Utilisateur> usersSelection ;
	
	public String saveUser() 
	{
		try 
		{
			userDao.persist(user);
			addMessageInfo("OK !!","Success");
			return "savesuccess";
		} 
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","L'utilisateur existe ou Champ obligatoire vide !!");
			return "savefail";
		}

	}
	public void oneUserSelection()
	{
		try
		{
			usr = usersSelection.get(0);
		}
		catch(IndexOutOfBoundsException e)
		{
			//Rien faire
		}
	}
	public String changeUser() 
	{
		try 
		{
			userDao.update(usr);
			addMessageInfo("OK !!","Success");
			return "savesuccess";
		} 
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","L'utilisateur existe ou Champ obligatoire vide !!");
			return "savefail";
		}

	}
	public String deleteUsers()
	{
		try
		{
		for(Utilisateur usr : usersSelection)
			userDao.delete(usr);
		return "delete";
		}
		catch(HibernateException e)
		{
			return "notdelete";
		}
		
	}
	public void listUsers() 
	{
		users = userDao.findAll();
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
	public UtilisateurDao getUserDao()
	{
		return userDao;
	}
	public void setUserDao(UtilisateurDao userDao)
	{
		this.userDao = userDao;
	}
	public Utilisateur getUser()
	{
		return user;
	}
	public void setUser(Utilisateur user)
	{
		this.user = user;
	}
	public List<Utilisateur> getUsers() {
		return users;
	}

	public void setUsers(List<Utilisateur> users) {
		this.users = users;
	}
	public List<Utilisateur> getUsersSelection() {
		return usersSelection;
	}

	public void setUsersSelection(List<Utilisateur> usersSelection) {
		this.usersSelection = usersSelection;
	}
	public Utilisateur getUsr() {
		return usr;
	}
	public void setUsr(Utilisateur usr) {
		this.usr = usr;
	}

}