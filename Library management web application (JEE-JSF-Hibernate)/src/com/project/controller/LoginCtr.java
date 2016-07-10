package com.project.controller;

import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;
import javax.faces.context.FacesContext;

import com.project.model.Utilisateur;
import com.project.dao.UtilisateurDao;


@ManagedBean(name="loginCtr")
@SessionScoped
public class LoginCtr 
{
	private String userName;
	private String userPassWord;
	private UtilisateurDao utilisateurDao;
	private static Utilisateur actualUser;
	public String connect()
	{
		utilisateurDao = new UtilisateurDao();
		actualUser = new Utilisateur();
		actualUser = utilisateurDao.findById(userName);
		if (actualUser != null && actualUser.getPassword().equals(userPassWord) && actualUser.getType().equals("admin"))
			return "successadmin";
		else if (actualUser != null && actualUser.getPassword().equals(userPassWord))
				return"success";
		addMessage("Attention !!", "Votre nom d'utilisateur ou votre mot de pass et incorrect !!");
		return"fail";
	}
	
	public String deconnect()
	{
		return "deconnect";
	}
	public void addMessage(String summary, String detail) 
	{
        FacesMessage message = new FacesMessage(FacesMessage.SEVERITY_WARN, summary, detail);
        FacesContext.getCurrentInstance().addMessage(null, message);
    }
	public String getUserName()
	{
		return userName;
	}
	public void setUserName(String userName)
	{
		this.userName = userName;
	}
	public String getUserPassWord()
	{
		return userPassWord;
	}
	public void setUserPassWord(String userPassWord)
	{
		this.userPassWord = userPassWord;
	}
	public static Utilisateur getActualUser() {
		return actualUser;
	}
	public void setActualUser(Utilisateur actualUser) {
		LoginCtr.actualUser = actualUser;
	}
}