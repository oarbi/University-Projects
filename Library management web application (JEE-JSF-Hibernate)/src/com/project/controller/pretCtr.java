package com.project.controller;

import java.util.Date;
import java.util.List;

import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;
import javax.faces.context.FacesContext;

import org.hibernate.HibernateException;

import com.project.dao.LivreDao;
import com.project.dao.MembreDao;
import com.project.dao.PretDao;
import com.project.model.Livre;
import com.project.model.Membre;
import com.project.model.Pret;
import com.project.model.PretId;



@ManagedBean(name="pretCtr")
@SessionScoped
public class pretCtr 
{
	private PretId id = new PretId();
	private PretId idptr = new PretId();
	private PretDao pretDao = new PretDao();
	private Pret pret = new Pret();
	private Pret prt = new Pret();
	private List<Pret> prets;
	private List<Pret> pretsSelection;
	private MembreDao mbrDao = new MembreDao();
	private LivreDao bkDao = new LivreDao();
	private Date dt;
	private long dtnow ;
	
	
	

	public String savePret()
	{
		try
		{
			int nbrmbr = 0,nbrbk = 0;
			Membre mbr = mbrDao.findById(id.getCin());
			Livre bk = bkDao.findById(id.getIsbn());
			if(bk==null && mbr==null)
			{
				addMessageWarn("Attention !!","Le membre et le livre n'existent pas ou Champ obligatoire vide !!");
				return "savefail";
			} else if (bk==null)
			{
				addMessageWarn("Attention !!","Le livre n'existe pas ou Champ obligatoire vide !!");
				return "savefail";
			} else if (mbr==null)
			{
				addMessageWarn("Attention !!","Le membre n'existe pas ou Champ obligatoire vide !!");
				return "savefail";
			}
			for(Pret pt:prets)
			{
				if( mbr.getCin() == pt.getMembre().getCin())
					nbrmbr++;
				if( bk.getIsbn() == pt.getLivre().getIsbn())
					nbrbk++;
			}
			if(nbrmbr >= LoginCtr.getActualUser().getNbrlim())
			{
				addMessageInfo("Attention !!","Le membre a atteint le nombre max de livre !!");
				return "savefail";
			}	
			if(nbrbk >= bk.getNbrdispo())
			{
				addMessageInfo("Attention !!","Le livre n'est pas disponible !!");
				return "savefail";
			}
			pret = new Pret(id,mbr,bk,dt);
			pretDao.persist(pret);
			addMessageInfo("OK !!","Success");
			return "savesuccess";
		}
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","Le pret existe !!");
			return "savefail";
		}
	}
	
	public void onePretSelection()
	{
		try
		{
			prt = pretsSelection.get(0);
			idptr = prt.getId();
		}
		catch(IndexOutOfBoundsException e)
		{
			//Rien faire
		}
		
	}
	
	public String changePret()
	{
		try
		{
			pretDao.update(prt);
			addMessageInfo("OK !!","Success");
			return "savesuccess";
		} 
		catch (HibernateException e) 
		{
			addMessageWarn("Attention !!","L'utilisateur existe ou Champ obligatoire vide !!");
			return "savefail";
		}
	}
	public String deletePret()
	{
		try
		{
			for(Pret p: pretsSelection)
				pretDao.delete(p);
			return "delete";
		}
		catch(HibernateException e)
		{
			return "notdelete";
		}
	}
	
	public void listPret()
	{
		prets = pretDao.findAll();
		dtnow = new Date().getTime() - (LoginCtr.getActualUser().getDureelim()*24*60*60*1000);
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
	public PretDao getPretDao() {
		return pretDao;
	}
	public void setPretDao(PretDao pretDao) {
		this.pretDao = pretDao;
	}
	public Pret getPret() {
		return pret;
	}
	public void setPret(Pret pret) {
		this.pret = pret;
	}
	public Pret getPrt() {
		return prt;
	}
	public void setPrt(Pret prt) {
		this.prt = prt;
	}
	public List<Pret> getPrets() {
		return prets;
	}
	public void setPrets(List<Pret> prets) {
		this.prets = prets;
	}
	public List<Pret> getPretsSelection() {
		return pretsSelection;
	}
	public void setPretsSelection(List<Pret> pretsSelection) {
		this.pretsSelection = pretsSelection;
	}
	public PretId getId() {
		return id;
	}
	public void setId(PretId id) {
		this.id = id;
	}
	public PretId getIdptr() {
		return idptr;
	}
	public void setIdptr(PretId idptr) {
		this.idptr = idptr;
	}
	public MembreDao getMbrDao() {
		return mbrDao;
	}
	public void setMbrDao(MembreDao mbrDao) {
		this.mbrDao = mbrDao;
	}
	public LivreDao getBkDao() {
		return bkDao;
	}
	public void setBkDao(LivreDao bkDao) {
		this.bkDao = bkDao;
	}
	public Date getDt() {
		return dt;
	}
	public void setDt(Date dt) {
		this.dt = dt;
	}
	public long getDtnow() {
		return dtnow;
	}

	public void setDtnow(long dtnow) {
		this.dtnow = dtnow;
	}
}
