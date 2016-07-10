package com.project.dao;

// Generated 10-Dec-2015 21:06:14 by Hibernate Tools 4.0.0

import java.util.List;


import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.hibernate.Query;
import org.hibernate.SessionFactory;
import org.hibernate.criterion.Example;


import com.project.util.HibernateUtil;
import com.project.model.Utilisateur;

/**
 * Home object for domain model class Utilisateur.
 * @see com.project.dao.Utilisateur
 * @author Hibernate Tools
 */
public class UtilisateurDao {

	private static final Log log = LogFactory.getLog(UtilisateurDao.class);

	private final SessionFactory sessionFactory = getSessionFactory();

	protected SessionFactory getSessionFactory() 
	{
		try 
		{
			return (SessionFactory) HibernateUtil.sessionFactory;
		} 
		catch (Exception e) 
		{
			log.error("Could not locate SessionFactory ", e);
			throw new IllegalStateException("Could not locate SessionFactory");
		}
	}

	private void openTransaction(){
		sessionFactory
		.getCurrentSession().beginTransaction();
	}
	
	private void closeTransaction(){
		sessionFactory
		.getCurrentSession().getTransaction().commit();
	}
	private void cancelTransaction(){
		sessionFactory
		.getCurrentSession().getTransaction().rollback();
	}
	
	public void persist(Utilisateur transientInstance) {
		log.debug("persisting Utilisateur instance");
		try {
			openTransaction();
			sessionFactory.getCurrentSession().persist(transientInstance);
			closeTransaction();
			log.debug("persist successful");
		} catch (RuntimeException re) {
			cancelTransaction();
			log.error("persist failed", re);
			throw re;
		}
	}

	public void update(Utilisateur instance) {
		log.debug("attaching dirty Utilisateur instance");
		try {
			openTransaction();
			sessionFactory.getCurrentSession().saveOrUpdate(instance);
			closeTransaction();
			log.debug("attach successful");
		} catch (RuntimeException re) {
			cancelTransaction();
			log.error("attach failed", re);
			throw re;
		}
	}

	public void delete(Utilisateur persistentInstance) {
		log.debug("deleting Utilisateur instance");
		try {
			openTransaction();
			sessionFactory.getCurrentSession().delete(persistentInstance);
			closeTransaction();
			log.debug("delete successful");
		} catch (RuntimeException re) {
			cancelTransaction();
			log.error("delete failed", re);
			throw re;
		}
	}

	public Utilisateur merge(Utilisateur detachedInstance) {
		log.debug("merging Utilisateur instance");
		try {
			Utilisateur result = (Utilisateur) sessionFactory
					.getCurrentSession().merge(detachedInstance);
			log.debug("merge successful");
			return result;
		} catch (RuntimeException re) {
			log.error("merge failed", re);
			throw re;
		}
	}

	public Utilisateur findById(java.lang.String id) {
		log.debug("getting Utilisateur instance with id: " + id);
		try {
			openTransaction();
			Utilisateur instance = (Utilisateur) sessionFactory.getCurrentSession().get("com.project.model.Utilisateur", id);
			closeTransaction();
			if (instance == null) {
				log.debug("get successful, no instance found");
			} else {
				log.debug("get successful, instance found");
			}
			return instance;
		} catch (RuntimeException re) {
			cancelTransaction();
			log.error("get failed", re);
			throw re;
		}
	}

	public List findByExample(Utilisateur instance) {
		log.debug("finding Utilisateur instance by example");
		try {
			List results = sessionFactory.getCurrentSession()
					.createCriteria("com.project.dao.Utilisateur")
					.add(Example.create(instance)).list();
			log.debug("find by example successful, result size: "
					+ results.size());
			return results;
		} catch (RuntimeException re) {
			log.error("find by example failed", re);
			throw re;
		}
	}
	public List<Utilisateur> findAll() 
	{
		try
		{
			openTransaction();
			Query query = sessionFactory.getCurrentSession().createQuery("FROM Utilisateur");
			List l = query.list();
			closeTransaction();
			log.debug("find all successful");
			return l;
		} catch(RuntimeException re)
		{
			cancelTransaction();
			log.error("find all failed", re);
			throw re;
		}
		
	}
}
