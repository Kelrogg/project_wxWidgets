#ifndef COMMAND_ITERATOR_ITERATOR_HPP
#define COMMAND_ITERATOR_ITERATOR_HPP

template <typename T>
class IIterator
{
public:
	using reference_type = T &;

	virtual bool HasNext() const = 0;
	virtual reference_type Get() const = 0;
	virtual void Next() = 0;
};

template <typename T>
using IIteratorPtr = std::unique_ptr<IIterator<T>>;

template <typename T>
using IIteratorSharedPtr = std::shared_ptr<IIterator<T>>;

template <typename T, typename IteratorT>
class IteratorWrapper : public IIterator<T>
{
public:
	using MyBase = IIterator<T>;

	using reference_type = typename MyBase::reference_type;

	IteratorWrapper(const IteratorT &begin, const IteratorT &end)
		: m_it(begin), m_end(end)
	{
	}

	bool HasNext() const override
	{
		return m_it != m_end;
	}

	reference_type Get() const override
	{
		if (m_it == m_end)
		{
			throw std::out_of_range("Can`t dereference end iterator");
		}
		return *m_it;
	}

	void Next() override
	{
		if (m_it == m_end)
		{
			throw std::out_of_range("Can`t increment end iterator");
		}
		++m_it;
	}

private:
	IteratorT m_it, m_end;
};

#endif
