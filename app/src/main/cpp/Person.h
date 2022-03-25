//
// Created by AILEE on 2022/3/23.
//

#ifndef TUTORIALS_JNILIB_PERSON_H
#define TUTORIALS_JNILIB_PERSON_H

#include <string>

/**
 * @class   Person
 * E-mail   lijie@fjirsm.ac.cn
 * Created by AILEE on 2022/3/23 17:32
 */
class Person {
public:
    /**
     * @brief       构造函数
     * @author      AILEE
     * @date        2022/3/23
     */
    Person();

    /**
     * @brief       设置姓名
     * @param[in]   name    姓名
     * @return      void
     * @author      AILEE
     * @date        2022/3/23
     */
    void setName(std::string name);

    /**
     * @brief       设置年龄
     * @param[in]   age     年龄
     * @return      void
     * @author      AILEE
     * @date        2022/3/23
     */
    void setAge(int age);

    /**
     * @brief       获取姓名
     * @return      string  姓名
     * @author      AILEE
     * @date        2022/3/23
     */
    std::string getName();

    /**
     * @brief       获取年龄
     * @return      int     年龄
     * @author      AILEE
     * @date        2022/3/23
     */
    int getAge();

private:
    std::string m_name;     ///< 姓名
    int         m_age;      ///< 年龄
};

#endif //TUTORIALS_JNILIB_PERSON_H
