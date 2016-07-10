package com.project.dao;

// Generated 10-Dec-2015 21:06:14 by Hibernate Tools 4.0.0

import java.util.List;

import javax.naming.InitialContext;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.hibernate.Query;
import org.hibernate.SessionFactory;
import org.hibernate.criterion.Example;

import com.project.model.Membre;
import com.project.util.HibernateUtil;

/**
 * Home object for domain model class Membre.
 * @see com.project.dao.Membre
 * @author Hibernate Tools
 */
public class MembreDao {

	private static final Log log = LogFactory.getLog(MembreDao.class);

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

	public void persist(Membre transientInstance) {
		log.debug("persisting Membre instance");
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

	public void update(Membre instance) {
		log.debug("attaching dirty Membre instance");
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

	public void delete(Membre persistentInstance) {
		log.debug("deleting Membre instance");
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

	public Membre merge(Membre detachedInstance) {
		log.debug("merging Membre instance");
		try {
			Membre result = (Membre) sessionFactory.getCurrentSession().merge(
					detachedInstance);
			log.debug("merge successful");
			return result;
		} catch (RuntimeException re) {
			log.error("merge failed", re);
			throw re;
		}
	}

	public Membre findById(int id) {
		log.debug("getting Membre instance with id: " + id);
		try {
			openTransaction();
			Membre instance = (Membre) sessionFactory.getCurrentSession().get(
					"com.project.model.Membre", id);
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

	public List findByExample(Membre instance) {
		log.debug("finding Membre instance by example");
		try {
			List results = sessionFactory.getCurrentSession()
					.createCriteria("com.project.model.Membre")
					.add(Example.create(instance)).list();
			log.debug("find by example successful, result size: "
					+ results.size());
			return results;
		} catch (RuntimeException re) {
			log.error("find by example failed", re);
			throw re;
		}
	}
	public List<Membre> findAll() 
	{
		try
		{
			openTransaction();
			Query query = sessionFactory.getCurrentSession().createQuery("FROM Membre");
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
