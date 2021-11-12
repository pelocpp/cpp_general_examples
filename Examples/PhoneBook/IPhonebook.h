// ===========================================================================
// IPhonebook.h
// ===========================================================================

#pragma once

class IPhonebook
{
    // public interface
    virtual size_t size() = 0;
    virtual bool insert(const std::string& firstName, const std::string& lastName, long number) = 0;
    virtual bool insert(const Contact&) = 0;
    virtual bool contains(const std::string& firstName, const std::string& lastName) = 0;
    virtual bool find(const std::string& firstName, const std::string& lastName, long& number) = 0;
    virtual std::vector<Contact> findAll(const std::string& lastName) = 0;
    virtual bool remove(const std::string& firstName, const std::string& lastName, long number) = 0;
    virtual bool update(const std::string& firstName, const std::string& lastName, long number) = 0;
    virtual void import(const IPhonebook& book) = 0;
    virtual std::string toString() = 0;
    virtual void sort() = 0;
};

// ===========================================================================
// End-of-File
// ===========================================================================
