package com.project.dao;

// Generated 10-Dec-2015 21:06:14 by Hibernate Tools 4.0.0

import java.util.List;

import javax.naming.InitialContext;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.hibernate.Query;
import org.hibernate.SessionFactory;
import org.hibernate.criterion.Example;

import com.project.model.Livre;
import com.project.util.HibernateUtil;

/**
 * Home object for domain model class Livre.
 * @see com.project.dao.Livre
 * @author Hibernate Tools
 */
public class LivreDao {

	private static final Log log = LogFactory.getLog(LivreDao.class);

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
	
	public void persist(Livre transientInstance) {
		log.debug("persisting Livre instance");
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

	public void update(Livre instance) {
		log.debug("attaching dirty Livre instance");
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

	public void delete(Livre persistentInstance) {
		log.debug("deleting Livre instance");
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

	public Livre merge(Livre detachedInstance) {
		log.debug("merging Livre instance");
		try {
			Livre result = (Livre) sessionFactory.getCurrentSession().merge(
					detachedInstance);
			log.debug("merge successful");
			return result;
		} catch (RuntimeException re) {
			log.error("merge failed", re);
			throw re;
		}
	}

	public Livre findById(long id) {
		log.debug("getting Livre instance with id: " + id);
		try {
			openTransaction();
			Livre instance = (Livre) sessionFactory.getCurrentSession().get(
					"com.project.model.Livre", id);
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

	public List findByExample(Livre instance) {
		log.debug("finding Livre instance by example");
		try {
			List results = sessionFactory.getCurrentSession()
					.createCriteria("com.project.model.Livre")
					.add(Example.create(instance)).list();
			log.debug("find by example successful, result size: "
					+ results.size());
			return results;
		} catch (RuntimeException re) {
			log.error("find by example failed", re);
			throw re;
		}
	}
	public List<Livre> findAll() 
	{
		try
		{
			openTransaction();
			Query query = sessionFactory.getCurrentSession().createQuery("FROM Livre");
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
