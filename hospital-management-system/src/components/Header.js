import React from 'react';
import Link from 'next/link';
import styles from '../styles/components.css';

const Header = () => {
    return (
        <header className={styles.header}>
            <h1>Hospital Management System</h1>
            <nav>
                <ul className={styles.navList}>
                    <li><Link href="/">Home</Link></li>
                    <li><Link href="/patients">Patients</Link></li>
                    <li><Link href="/appointments">Appointments</Link></li>
                    <li><Link href="/staff">Staff</Link></li>
                </ul>
            </nav>
        </header>
    );
};

export default Header;