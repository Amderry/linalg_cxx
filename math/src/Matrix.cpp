#include "Matrix.hpp"
#include "MMultiplication.hpp"

namespace math
{
	Matrix::Matrix(unsigned int m, unsigned int n)
		:m(m), n(n)
	{
	}

	Float_Matrix::Float_Matrix(unsigned int m, unsigned int n, std::unique_ptr<float[]> data)
		: Matrix(m, n), m_data(std::move(data))
	{
	}

	Float_Matrix::Float_Matrix(Float_Matrix&& rhs) noexcept
		: Matrix(rhs.m, rhs.n), m_data(std::move(rhs.m_data))
	{
		rhs.m = 0;
		rhs.n = 0;
		rhs.m_data = nullptr;
	}

	Float_Matrix& math::Float_Matrix::operator=(Float_Matrix&& rhs) noexcept
	{
		this->m = rhs.m;
		this->n = rhs.n;
		this->m_data = std::move(rhs.m_data);
		rhs.m = 0;
		rhs.n = 0;
		rhs.m_data = nullptr;
		return *this;
	}

	std::unique_ptr<Float_Matrix> Float_Matrix::copy() const
	{
		auto new_data = std::make_unique<float[]>(this->m * this->n);
		std::copy(this->m_data.get(), this->m_data.get() + this->m * this->n, new_data.get());
		auto new_matrix = std::make_unique<Float_Matrix>(this->m, this->n, std::move(new_data));
		return new_matrix;
	}

	Double_Matrix::Double_Matrix(unsigned int m, unsigned int n, std::unique_ptr<double[]> data)
		: Matrix(m, n), m_data(std::move(data))
	{
	}

	Double_Matrix::Double_Matrix(Double_Matrix&& rhs) noexcept
		: Matrix(rhs.m, rhs.n), m_data(std::move(rhs.m_data))
	{
		rhs.m = 0;
		rhs.n = 0;
		rhs.m_data = nullptr;
	}

	Double_Matrix& Double_Matrix::operator=(Double_Matrix&& rhs) noexcept
	{
		this->m = rhs.m;
		this->n = rhs.n;
		this->m_data = std::move(rhs.m_data);
		rhs.m = 0;
		rhs.n = 0;
		rhs.m_data = nullptr;
		return *this;
	}

	std::unique_ptr<Double_Matrix> Double_Matrix::copy() const
	{
		auto new_data = std::make_unique<double[]>(this->m * this->n);
		std::copy(this->m_data.get(), this->m_data.get() + this->m * this->n, new_data.get());
		auto new_matrix = std::make_unique<Double_Matrix>(this->m, this->n, std::move(new_data));
		return new_matrix;
	}
}