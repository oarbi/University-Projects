package com.project.controller;

import java.util.List;

import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;
import javax.faces.context.FacesContext;

import org.hibernate.HibernateException;

import scala.Int;

import com.project.dao.MembreDao;
import com.project.model.Membre;




@ManagedBean(name="memberCtr")
@SessionScoped
public class MembreCtr 
{
	private MembreDao memberDao = new MembreDao();
	private Membre member = new Membre();
	private Membre membr = new Membre();
	private List<Membre> members;
	private List<Membre> membersSelection;
	
	public String saveMember()
	{
		try
		{
			if(Integer.toString(member.getCin()).length() == 8 )
			{
				memberDao.persist(member);
				addMessageInfo("OK !!","Success");
				return "savesuccess";
			}
			else
			{
				addMessageWarn("Attention !!","CIN doit étre composé de 8 chiffres !!");
				return "savefail";
			}
		}
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","L'utilisateur existe ou Champ obligatoire vide !!");
			return "savefail";
		}
	}
	
	public void oneMemberSelection()
	{
		try
		{
			membr = membersSelection.get(0);
		}
		catch(IndexOutOfBoundsException e)
		{
			//Rien faire
		}
	}
	public String changeMember() 
	{
		try 
		{
			memberDao.update(membr);
			addMessageInfo("OK !!","Success");
			return "savesuccess";
		} 
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","L'utilisateur existe ou Champ obligatoire vide !!");
			return "savefail";
		}

	}
	public String deleteMember()
	{
		try
		{
			for(Membre mem : membersSelection)
				memberDao.delete(mem);
			return "delete";
		}
		catch(HibernateException e)
		{
			return "notdelete";
		}
		
	}
	public void listMembers()
	{
		members = memberDao.findAll();
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
	public MembreDao getMemberDao() {
		return memberDao;
	}
	public void setMemberDao(MembreDao memberDao) {
		this.memberDao = memberDao;
	}
	public Membre getMember() {
		return member;
	}
	public void setMember(Membre member) {
		this.member = member;
	}
	public List<Membre> getMembers() {
		return members;
	}
	public void setMembers(List<Membre> members) {
		this.members = members;
	}
	public List<Membre> getMembersSelection() {
		return membersSelection;
	}
	public void setMembersSelection(List<Membre> membersSelection) {
		this.membersSelection = membersSelection;
	}
	public Membre getMembr() {
		return membr;
	}

	public void setMembr(Membre membr) {
		this.membr = membr;
	}
}
